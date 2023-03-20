using namespace std;
// jetson -> arduino : 1 2 3 4 수신받은 메세지
// arduino -> jetson : A B C D 송신하는 메세지

#include <Servo.h> // 서보모터
#include <SoftwareSerial.h> // 시리얼 통신

// 기본 설정
Servo fishDivider_ServoA; // A ~ D분류 서보모터
Servo fishDivider_ServoB;
Servo fishDivider_ServoC;

const int LED_A = 4; // A ~ D 통로별 LED (A ~ C : Green / D : Red)
const int LED_B = 5;
const int LED_C = 6;
const int LED_D = 7; // Red

const int fishDivider_numA = 8; // A ~ D 분류 모터
const int fishDivider_numB = 9;
const int fishDivider_numC = 10;
const int fishDivider_numD = 11;

const int servoResetSW = 13; // 서보모터 reset 버튼

bool detectValue = 0; // 최초로 컨베이어 벨트의 물고기 감지
bool objectDetect = 1;
const int detectPhotoSensor = 0; // 최초의 물고기 인식 광센서

bool divide_state = 0; // 메인에서 분리 State ON/OFF
int count = 0; // Timer Delay

char recMsg[10] = ""; // 받은 문자열 임시 저장공간
char* nuid[2] = {}; // 받은 값 임시 저장공간
char fishDivide = {}; // 물고기 분류값
char jetsonSend = {}; // 젯슨에서 보낸 메세지

// 최초로 컨베이어 벨트의 물고기 감지
void firstDetect() {
    int firstPhotoSensor = analogRead(detectPhotoSensor); // 물체 인식 센서 작동
    if (firstPhotoSensor > 250) {
        detectValue = 0;
    }
    else if (firstPhotoSensor <= 250) {
        detectValue = 1;
    }
}

// 광센서로 물고기 감지 이후 카운터 및 서보모터 작동
int photoState(int photoSensorNum) {
    while (1) {
        int photoValue = analogRead(photoSensorNum);  // photoSensorNum : 1 ~ 4 = A1 ~ A4
        if (photoValue < 250) {
            break;
        }
        else continue;
    }

    char countResult = {}; // 아두이노에서 젯슨으로 카운트 결과 송신

    if (photoSensorNum == 1) { // 1번 수조 카운트
        fishDivider_ServoA.write(90); // 문 닫기
        digitalWrite(LED_A, HIGH);
        Serial.print('A');
    }
    else if (photoSensorNum == 2) { // 2번 수조 카운트
        fishDivider_ServoB.write(90);
        digitalWrite(LED_B, HIGH);
        Serial.print('B');
    }
    else if (photoSensorNum == 3) { // 3번 수조 카운트
        fishDivider_ServoC.write(90);
        digitalWrite(LED_C, HIGH);
        Serial.print('C');
    }
    else if (photoSensorNum == 4) { // 4번 수조 카운트
        digitalWrite(LED_D, HIGH);
        Serial.print('D'); 
    }

    fishDivide = '0';
    count = 0; // LED를 Off하기 위한 초기화 변수
}

void LED_Off() { // LED 모두 Off하는 함수
    if (count == 15000) {
        digitalWrite(LED_A, LOW);
        digitalWrite(LED_B, LOW);
        digitalWrite(LED_C, LOW);
        digitalWrite(LED_D, LOW);
    }
    count++;
}

// 서보모터 및 통신 세팅
void setup() {
    Serial.begin(9600); // 화면 출력
    fishDivider_ServoA.attach(fishDivider_numA); // 모터 A ~ C 세팅
    fishDivider_ServoB.attach(fishDivider_numB);
    fishDivider_ServoC.attach(fishDivider_numC);
    pinMode(LED_A, OUTPUT); // LED A ~ D 세팅
    pinMode(LED_B, OUTPUT);
    pinMode(LED_C, OUTPUT);
    pinMode(LED_D, OUTPUT);
}

// 메인 함수
void loop() {
    
    firstDetect(); // 최초로 컨베이어 벨트의 물고기 감지

    if ((detectValue == 1) && (objectDetect == 1)) { // 물체 감지시 jetson으로 메세지 송신
        Serial.print('S'); // 최초에 물고기 감지시 'S'를 jetson으로 송신
        objectDetect = 0;
        delayMicroseconds(1);
    }
    else if ((detectValue == 0) && (objectDetect == 0)) {
        objectDetect = 1;
        return;
    }

    if (Serial.available()) { // 통신이 확인 되었을때 시행
        fishDivide = Serial.read();
        divide_state = 1;
    }
    else {
        divide_state = 0;
    }

    if (divide_state == 1) { // 물고기 분류 모터 작동
        if (fishDivide == '1') { // Serial.println("1번 모터 작동");
            fishDivider_ServoA.write(135); // 통로로 물고기가 들어가게 모터 작동
            photoState(1);
            
        }
        else if (fishDivide == '2') { // Serial.println("2번 모터 작동");
            fishDivider_ServoB.write(135);
            photoState(2);
        }
        else if (fishDivide == '3') { // Serial.println("3번 모터 작동");
            fishDivider_ServoC.write(135);
            photoState(3);
        }
        else if (fishDivide == '4') { // Serial.println("4번 예외 처리 가동");
            photoState(4);
        }
        divide_state = 0; // 분류 완료
    }

    LED_Off(); // LED A ~ D Off

}