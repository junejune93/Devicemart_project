# 개요

## 공모전 홈페이지

---

[🌏디바이스마트 / 디바이스마트 공모전](https://www.devicemart.co.kr/board/?id=award_board)<br/> 
[🎥최종 구현 동영상](https://www.youtube.com/watch?v=KhIYbObVZ9c)

## 👨‍👨‍👧‍👧프로젝트 팀원

---

|  | 이  름 | 담당 파트 |
| --- | --- | --- |
| 팀장 | 허준 | Arudino Main, Anaconda3 Building, YoloV5 Sub, Arduino-Jetson 통신, Notion 관리, GitHub 관리 |
| 팀원 | 김윤희 | Jetson-Raspberry Socket 통신, Jetson Building, YoloV5 Sub, Maria DB 설정, GitHub 관리 |
| 팀원 | 김승환 | Machine Learning Main, Data Labeling, Qt5 Sub |
| 팀원 | 박선규 | Qt5 Main, Data Labeling, Machine Learning Sub |
| 팀원 | 유다원 | YoloV5 Main, Jetson Building, Arduino-Jetson 통신, 3D Printing, 작품 외관 설계 및 구현 |

## 프로젝트 명

---

🐟 Fishify (Fish Identify)

## 프로젝트 주제

---

Open CV를 활용한 치어(larval fish) 분류

---

## 아이디어 선정 및 기술 요건 파악

1. 계획 기간: 2023년 2월 13일 → 2023년 2월 18일<br/> 
2. 실제 진행 기간: 2023년 2월 13일 → 2023년 2월 15일<br/> 
3. 진행 단계: 완료<br/> 
4. 참여 인원: 김윤희, 허준, 유다원, 박선규, 김승환<br/> 

## 아이디어 선정

---

📌 주제 : OpenCV를 활용한 치어(Larval Fish) 분류

1️⃣ 선정 이유

1. 관상어 산업은 커지고 있지만 스포이드를 이용해 육안으로 직접 구별하는 비효율적인 방법으로 치어를 분류중임
2. 해외에서는 치어 분류 장치가 개발이 되어 활용이 되고 있지만 국내에는 아직 미구현 되어있음

2️⃣ 기술 구현 방식

1. 이론상 구현 방식

1) 수조간에 다리를 연결해 치어들이 지나갈수 있는 통로를 설정함 / 적외선 센서를 통해 치어가 통로에 있는지 

확인 → 적외선 확인 후 문 열리고 치어 한마리를 통로로 보냄

2) 통로 측면에 카메라로 치어를 인식해 종류 확인 (측면에서 치어의 형태 및 무늬, 투명도 등으로 구분)

3) 종류 판별 후 서보모터 작동

4) 분류 완료

1.  실제 구현 방식
    1. 적외선 센서를 통해 컨베이어 위에 치어가 있는지 확인 → 적외선 확인 후 문 열리고 모형 치어를 통로로 보냄
    2. 통로 위측에 있는 카메라로 치어를 인식해 종류 확인
    3. 종류 판별 후 컨베이어 이동 및 분류
    4. 분류 완료

3️⃣ 분류할 치어 종류 (유다원 3D 지원 가능)

1. 크기 : 10mm
2. 색상 : 투명, 흰색, 문양(점, 줄무늬, 옆선)
3. 모양(shape)

4️⃣ 예외 처리

1. 잘못 들어온 치어 분류
2. 물고기 떡밥 등 각종 이물질

5️⃣ 추후 추가 구현

1. 치어별 연령대 확인 (치어별 생후 몇개월인지)
2. 돌연변이 치어 판별 (상업성이 떨어지는 치어 분류)
3. 사체 치어 처리
4. 수조 상태 파악 (ex. 수조 오염도 구분, 수조 온도 측정)

6️⃣ 기대효과

1. 육안으로 파악하기 힘든 객체를 정확한 수치와 명확한 종으로 관리 가능함
2. 기술을 구현함으로써, 인건비 절약 및 불필요한 양식과정 단축가능성

7️⃣ 기술활용방안

1. 현재 지속적으로 문제가 되고 있는 멸종위기 혹은 희귀 종에 대하여 조기 발견 함으로써 체계적인 관리를 가능하게 함 
    
    (실제 많은 종이 살고있는 바다의 환경 적용 시)
    
2. 다른 기술 (Active Sonar 등) 을 융합하여 더 정확하고 구체적인 감지 및 다른 기술들로 구현가능
---
## 개발 환경
---
 **JetsonNano**
    
    JetsonNano 4.6.0.66
    Python 3.8.1
    YOLOv5
    OpenCV 4.6.0
    Pytorch 1.13.1
    Anaconda 3
    Pycharm
    
 **Raspberry Pi**
    
    Raspberry Pi 4 Model B Rev 1.4 / Linux 11 
    Qt5
    Maria DB
    
 **Arduino**
    
    Arduino Mega 2580
    VS Code
    
 **Machine Learning**
    
    Google Colab
    Roboflow
    Pytorch

## 개발 일지

<aside>
💡 프로젝트 진행사항

</aside>

| 날  짜 | 내  용 |
| --- | --- |
| 23.02.10 (금) | 1차 아이디어 회의 |
| 02.13 (월) | 2차 아이디어 회의 |
| 02.14 (화) | 최종 아이디어 회의 |
| 02.15 (수) | 단계별 계획 수립 |
| 02.16 (목) ~ 02.28 (화) | Jetson Nano 빌딩 설정 |
| 02.20 (월) ~ 02.22 (수) | (Python) 얼굴 인식 코드 Linux에서 시행 |
| 02.21 (화) ~ 02.22 (수) | (C++, Python) 얼굴 인식 코드 Window에서 시행 |
| 02.23 (목) | (Python) 고양이 인식 Linux 환경에서 시행 |
| 02.27 (월) | 아이디어 발표 |
| 02.28 (화) | 3D 프린터로 치어 모형 제작 |
| 02.29 (수) ~ 03.04 (금) | YOLO 버젼 선정 및 YOLOv5로 최종 선정 |
| 03.04 (금) ~ 03.28 (화) | (Colab) 물고기 데이터 라벨링  |
| 03.02 (목) ~ 03.04 (금) | Arduino-Jetson간 통신 설정 // I2C → UART 변경 |
| 03.03 (금) ~ 03.04 (토) | (YOLOv5) CSI 카메라 작동 여부 확인 // CSI → WebCam으로 변경 |
| 03.04 (토) ~ 03.08 (수) | (YOLOv5) WebCam으로 물체 인식 후 터미널 환경에서 단순 결과 출력 |
| 03.04 (토) | 컨베이어 벨트 동작 확인 |
| 03.06 (월) ~ 03.22 (수) | (Colab) 물고기 표본 딥러닝 시행 |
| 03.06 (월) ~ 03.08 (수) | 기초적인 컨베이어 벨트 작동 및 통신 구현 |
| 03.09 (목) ~ 03.15 (수) | (Arduino-Jetson) UART 통신 구현 // C++-Python |
| 03.12 (일) ~ 03.15 (수) | (Jetson-Raspberry) 소켓 통신 구현 // Python-Python |
| 03.13 (월) ~ 03.16 (목) | (Arduino) 코드 대폭 수정 |
| 03.13 (월) ~ 03.15 (수) | (MariaDB) DB 구축 및 Jetson-Raspberry 간 Data 송수신 확인 |
| 03.14 (화) | (Anaconda3) Window에서 치어 분류 환경 설정 |
| 03.15 (수) ~ 03.22 (수) | (Qt) Raspberry용 기초적인 GUI 구현 |
| 03.18 (토) ~ 03.31 (금) | 보고서 작성 |
| 03.20 (월) ~ 03.30 (목) | 하우징 구현 |
| 03.20 (월) | (Arduino) LED 기능 구현 |
| 03.21 (화) | 프로토타입 1차 테스트 |
| 03.22 (수) ~ 03.28 (화) | (Qt) Raspberry용 GUI 추가 기능 구현 |
| 03.23 (목) ~ 03.28 (화) | (Colab) 물고기 인식률을 높이기 위한 추가 딥러닝 시행 |
| 03.24 (금) | (Arduino) Timer 인터럽트 구현 및 예외처리 |
| 03.28 (화) | 프로토타입 2차 테스트 |
| 03.30 (목) | 최종 결과물 1차 테스트 |
| 03.31 (금) | 최종 결과물 2차 테스트 및 보고서 제출 |

