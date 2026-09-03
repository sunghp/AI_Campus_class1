#include <stdio.h>
#include <string.h>
//이동 로봇의 모터 적정성 여부 판단

int main(void) 
{
    int N;                              //변수 선언 및 초기화
    double m, SF, DM;
    double R;
    double tau;
    double G;


    double c = 0.018, g = 9.81, W;
    double F_min, F_motor, m_max;

    printf("구동 바퀴수를 입력하세요: ");       //변수 입력
    scanf("%d", &N);
    printf("총 하중을 입력하세요(kg): ");
    scanf("%lf", &m);
    printf("안전 계수를 입력하세요: ");
    scanf("%lf", &SF);
    printf("설계 마진을 입력하세요: ");
    scanf("%lf", &DM);
    printf("바퀴 반지름을 입력하세요(m): ");
    scanf("%lf", &R);
    printf("정격 토크를 입력하세요(Mn): ");
    scanf("%lf", &tau);
    printf("감속비를 입력하세요: ");
    scanf("%lf", &G);

    W = m * g;                              //중량 계산
    F_min = c * W * SF * DM;                //모터에 필요한 최소 견인력
    F_motor = tau * G / R * N;              //모터가 낼 수 있는 견인력
    m_max = F_motor / (c * SF * DM * g);    //모터가 최대로 들 수 있는 질량

    printf("총 하중(kg): %.1lf\n", m);          //결과 출력
    printf("구동 바퀴수: %d\n", N);
    printf("모션 정격 토크(Nm): %.2lf\n", tau);
    printf("감속비: %.1lf\n", G);
    printf("바퀴 반지름(m): %.3lf\n\n", R);

    printf("필요한 최소 견인력(N): %.1lf\n", F_min);
    printf("모터가 낼 수 있는 견인력(N): %.1lf\n", F_motor);
    printf("모터가 받을 수 있는 최대 질량(kg): %.2lf\n", m_max);

    if (F_min <= F_motor)                   //적정성 여부 판단
        {
            printf("판정: 만족\n");
        }
    else
        {
            printf("판정: 불만족 (더 큰 모터나 감속비가 필요합니다!)\n");
        }

    return 0;
}
