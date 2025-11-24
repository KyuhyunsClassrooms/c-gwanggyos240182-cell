// 필요한 헤더 선언
#include <stdio.h> // 표준 입출력 라이브러리 포함

// GPU 냉각 데이터 구조체 정의
struct Cooling {              
    char gpuName[20];        // GPU 이름
    float temperature;        // 온도
    int fanSpeed;             // 팬 속도
    float power;              // 전력 사용량
    float efficiency;         // 냉각 효율
};

// 구조체 배열 선언
struct Cooling data[100];     // GPU 정보 저장 배열
int count = 0;                 // 현재 저장된 개수

// 효율 계산 함수
void calcEfficiency(int index) { // index 번째 GPU 효율 계산
    data[index].efficiency = (data[index].fanSpeed / data[index].temperature);
}

// 평균 온도 계산 함수
float getAverageTemperature() {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += data[i].temperature;
    }
    return (count > 0) ? sum / count : 0;
}

// 최고 효율 GPU 출력
void printBestGPU() {
    if (count == 0) {
        printf("등록된 데이터가 없습니다.");
        return;
    }

    int bestIndex = 0;
    for (int i = 1; i < count; i++) {
        if (data[i].efficiency > data[bestIndex].efficiency) {
            bestIndex = i;
        }
    }

    printf("===== 최고 효율 GPU 정보 =====");
    printf("GPU 이름: %s", data[bestIndex].gpuName);
    printf("온도: %.2f", data[bestIndex].temperature);
    printf("팬 속도: %d", data[bestIndex].fanSpeed);
    printf("전력 사용량: %.2f", data[bestIndex].power);
    printf("효율: %.2f", data[bestIndex].efficiency);
}

// 과열 감지
void checkOverheat(int index) {
    if (data[index].temperature > 80) {
        printf("주의: %s GPU 과열됨! (%.2f°C)", data[index].gpuName, data[index].temperature);
    }
}

int main() {
    int n;
    printf("입력할 GPU 개수: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("%d번째 GPU 이름: ", i + 1);
        scanf("%s", data[count].gpuName);

        printf("온도 입력: ");
        scanf("%f", &data[count].temperature);

        printf("팬 속도 입력: ");
        scanf("%d", &data[count].fanSpeed);

        printf("전력 입력: ");
        scanf("%f", &data[count].power);

        calcEfficiency(count);
        checkOverheat(count);
        count++;
    }

    printf("전체 평균 온도: %.2f", getAverageTemperature());
    printBestGPU();

    return 0;
}