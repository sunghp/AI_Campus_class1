#include <stdio.h>
#include <math.h>
//이동 로봇의 최대 견인력과 등판 가능 경사각

int main(void)
{
    double m, T_m;          //변수 선언
    int N_m;
    double G, eta;
    const double g = 9.81;
    double r, c, SF;
    double T_tot, F_avail, F_need, sin_theta, theta, deg, grade;

    printf("총 질량을 입력하세요(kg): ");   //변수 입력
    scanf("%lf", &m);
    printf("모터 정격토크를 입력하세요(Nm): ");
    scanf("%lf", &T_m);
    printf("구동 모터수를 입력하세요: ");
    scanf("%d", &N_m);
    printf("감속비를 입력하세요: ");
    scanf("%lf", &g);
    printf("구동 효율을 입력하세요: ");
    scanf("%lf", &eta);
    printf("바퀴 반지름을 입력하세요(m): ");
    scanf("%lf", &r);
    printf("구름 계수를 입력하세요: ");
    scanf("%lf", &c);
    printf("안전 계수를 입력하세요: ");
    scanf("%lf", &SF);

    T_tot = N_m * T_m * G * eta;                    //총 구동 토크
    F_avail = T_tot / r;                            //가용 견인력
    sin_theta = (F_avail / SF - (c*m*g)) / (m*g);   //clip(sin_theta,0,1)
    if (sin_theta>1) sin_theta = 1;
    if (sin_theta<0) sin_theta = 0;
    F_need = m * g * sin_theta + (c*m*g);           //필요 견인력
    theta = asin(sin_theta);                        //등판 가능한 최대 각
    deg = theta * 180 / 3.141592;                   
    grade = tan(theta) * 100;                       //등판율


    printf("\n[결과]\n");                            //결과 출력
    printf("총 구동 토크[Nm]: %.2lf\n", T_tot);
    printf("가동 견인력[N]: %.2lf\n", F_avail);
    printf("필요 견인력[N]: %.2lf\n", F_need);
    printf("등판 가능 최대 각[deg]: %.2lf\n", deg);
    printf("등판율[%%]: %.2lf\n", grade);
    printf("[가정: 마찰한계 무시, 구름저항 c 포함, 안전계수 SF 적용]\n");

    return 0;
}