#include <stdio.h>

/*
    1. [설계]에서 정의한 변수, 배열, (필요하면) 구조체를 여기에 선언하세요.
    
    예시 - 배열 사용:
    struct Cooling data[100];   // Cooling 구조체 배열 100개 선언
    int count = 0;              // 현재 저장된 데이터 개수

    
    예시 - 구조체 사용 (선택):
    struct Cooling {                
    char gpuName[20];       // GPU 이름 저장
    float temperature;      // 온도 저장
    int fanSpeed;           // 팬 속도 저장
    float power;            // 전력 사용량 저장
    float efficiency;       // 냉각 효율 저장
};

*/


/*
    2. [알고리즘]에서 설계한 핵심 기능 함수들을 여기에 선언하세요.
    // 특정 GPU의 냉각 효율 계산 함수
    void calcEfficiency(int index);          // index번째 GPU의 효율 계산

    // 저장된 모든 GPU의 평균 온도 계산 함수
    float getAverageTemperature();           // 평균 온도 반환

    // 최고 효율 GPU 정보 출력 함수
    void printBestGPU();                     // 효율이 가장 높은 GPU 출력

    // 특정 GPU의 과열 여부 확인 함수
    void checkOverheat(int index);           // index번째 GPU가 과열인지 확인
    int wrongFunc(double a, b);            
    void imaginaryFunc();                    

*/


int main() {
    
    printf("--- C언어 미니 프로젝트 시작! ---\n");

    /*
        3. [알고리즘]에서 설계한 main 함수의 흐름을
           여기에 C언어로 자유롭게 구현하세요.
#include <stdio.h> // 표준 입출력 라이브러리 포함

/*  
 */

// GPU 냉각 데이터 구조체 정의
struct Cooling {                // Cooling 구조체 시작
    char gpuName[20];           // GPU 이름 저장
    float temperature;          // 온도 저장
    int fanSpeed;               // 팬 속도 저장
    float power;                // 전력 사용량 저장
    float efficiency;           // 냉각 효율 저장
};                              // 구조체 정의 끝

// 배열 선언
struct Cooling data[100];       // Cooling 구조체 배열 100개 선언
int count = 0;                  // 현재 저장된 데이터 개수

// 존재하지 않는 타입 선언 
int totalPowerUsed;             // 전력 합계를 저장 (정상)
floaat tempSum = 0;             

// 효율 계산 함수 선언
void calcEfficiency(int index);         // index번째 GPU 효율 계산

// 평균 온도 계산 함수 선언
float getAverageTemperature();          // 평균 온도 계산

// 최고 효율 GPU 출력 함수 선
void printBestGPU();                    // 최고 효율 GPU 출력

// 과열 감지 함수 선언
void checkOverheat(int index);          // 과열 여부 확인
int wrongFunc(double a, b);           
void imaginaryFunc();             
    
    
    return 0;
}
