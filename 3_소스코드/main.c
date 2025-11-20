#include <stdio.h> // 표준 입출력 라이브러리를 포함

// GPU 냉각 데이터 구조체 정의
struct Cooling {                // Cooling 구조체 선언 시작
    char gpuName[20];           // GPU 이름을 저장하는 문자 배열
    float temperature;          // GPU 온도를 저장하는 변수
    int fanSpeed;               // 팬 속도(RPM)를 저장하는 변수
    float power;                // GPU 전력 소비량 저장
    float efficiency;           // 계산된 냉각 효율 저장
};                              // 구조체 선언 종료

struct Cooling data[100];       // GPU 정보를 최대 100개 저장하는 구조체 배열
int count = 0;                  // 현재 저장된 GPU 개수를 저장하는 변수
float tempSum = 0;              // 평균 계산을 위해 전체 온도 합계를 저장하는 변수

// 특정 GPU의 냉각 효율을 계산하는 함수
void calcEfficiency(int index) {    // index 번째 GPU의 효율을 계산
    if (data[index].temperature > 0)    // 온도가 0보다 클 때만 계산
        data[index].efficiency = (data[index].fanSpeed / data[index].temperature) * 10; // 효율 계산 공식
    else
        data[index].efficiency = 0;     // 0으로 나누는 상황 방지
}

// 저장된 GPU들의 평균 온도를 계산하는 함수
float getAverageTemperature() {    // 평균 온도를 float형으로 반환
    if (count == 0) return 0;      // 데이터가 없으면 0 반환

    tempSum = 0;                   // 합계를 0으로 초기화
    for (int i = 0; i < count; i++) { // 전체 GPU 반복
        tempSum += data[i].temperature; // 온도 누적
    }
    return tempSum / count;        // 평균값 반환
}

// 최고 효율을 가진 GPU를 출력하는 함수
void printBestGPU() {              // 효율이 가장 높은 GPU 출력
    if (count == 0) {              // 데이터가 없을 때 처리
        printf("GPU 데이터가 없습니다.\n");
        return;
    }

    int bestIndex = 0;             // 첫 번째 GPU를 비교 기준으로 설정
    for (int i = 1; i < count; i++) {  // 전체 GPU 비교
        if (data[i].efficiency > data[bestIndex].efficiency) // 더 높은 효율 찾기
            bestIndex = i;
    }

    // 최고 효율 GPU 정보 출력
    printf("\n=== 최고 효율 GPU ===\n");
    printf("이름: %s\n", data[bestIndex].gpuName);
    printf("온도: %.1f°C\n", data[bestIndex].temperature);
    printf("팬 속도: %dRPM\n", data[bestIndex].fanSpeed);
    printf("전력: %.1fW\n", data[bestIndex].power);
    printf("효율: %.2f\n", data[bestIndex].efficiency);
}

// GPU 과열 여부를 판단하는 함수
void checkOverheat(int index) {    // index 번째 GPU의 온도 체크
    if (data[index].temperature >= 80)  // 온도가 80도 이상이면
        printf("⚠ 경고: %s 은(는) 과열 상태입니다!\n", data[index].gpuName);
    else
        printf("%s 정상 온도입니다.\n", data[index].gpuName);
}

// 정정된 함수: 두 숫자를 더해 반환하는 예제 함수
int wrongFunc(double a, int b) {   // double + int 계산
    return (int)(a + b);           // 결과를 int로 변환해 반환
}

// 실존하는 예제용 함수
void imaginaryFunc() {             // 단순 출력 기능 함수
    printf("imaginaryFunc 실행됨 (예시 함수)\n");
}

// 메인 함수 시작
int main() {                       // 프로그램 시작 지점
    count = 2;                     // GPU 데이터 2개 등록

    // 첫 번째 GPU 데이터 입력
    sprintf(data[0].gpuName, "RTX4090");  // GPU 이름 저장
    data[0].temperature = 75.0;            // 온도 저장
    data[0].fanSpeed = 1800;               // 팬 속도 저장
    data[0].power = 350.0;                 // 전력 저장
    calcEfficiency(0);                     // 효율 계산 수행

    // 두 번째 GPU 데이터 입력
    sprintf(data[1].gpuName, "RTX4080");  // GPU 이름 저장
    data[1].temperature = 82.5;            // 온도 저장
    data[1].fanSpeed = 1600;               // 팬 속도 저장
    data[1].power = 300.0;                 // 전력 저장
    calcEfficiency(1);                     // 효율 계산 수행

    printf("평균 온도: %.2f°C\n", getAverageTemperature()); // 평균 온도 출력
    printBestGPU();                        // 최고 효율 GPU 출력
    checkOverheat(0);                      // 첫 번째 GPU 과열 체크
    checkOverheat(1);                      // 두 번째 GPU 과열 체크

    imaginaryFunc();                       // 예제 함수 실행

    return 0;                              // 프로그램 종료
}
