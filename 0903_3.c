#include <stdio.h>
#include <math.h>

int main(void)
{
    double m, T_m;
    int N_m;
    double g, eta;
    double r, c, SF;
    double T_tot, F_avail, F_need, sin_theta, theta, deg, grade;

    printf("총 질량을 입력하세요: ");
    scanf("%lf", &m);
    printf("모터 정격토크를 입력하세요: ");
    scanf("%lf", &T_m);
    printf("구동 모터수를 입력하세요: ");
    scanf("%d", &N_m);
    printf("감속비를 입력하세요: ");
    scanf("%lf", &g);
    printf("구동 효율을 입력하세요: ");
    scanf("%lf", &eta);
    printf("바퀴 반지름을 입력하세요: ");
    scanf("%lf", &r);
    printf("구름 계수를 입력하세요: ");
    scanf("%lf", &c);
    printf("안전 계수를 입력하세요: ");
    scanf("%lf", &SF);

    T_tot = N_m * T_m * g * eta;
    F_avail = T_tot / r;
    sin_theta = (F_avail / SF - (c*m*g)) / (m*g);
    if (sin_theta>1) sin_theta = 1;
    if (sin_theta<0) sin_theta = 0;
    F_need = m * g * sin_theta + (c*m*g);
    theta = asin(sin_theta);
    deg = theta * 180 / 3.141592;
    grade = tan(theta) * 100;


    printf("\n[결과]\n");
    printf("총 구동 토크: %.2lf\n", T_tot);
    printf("가동 견인력: %.2lf\n", F_avail);
    printf("필요 견인력: %.2lf\n", F_need);
    printf("등판 가능 최대 각: %.2lf\n", deg);
    printf("등판율: %.2lf\n", grade);
    printf("[가정: 마찰한계 무시, 구름저항 c포함, 안전계수 SF 적용]\n");
    return 0;
}