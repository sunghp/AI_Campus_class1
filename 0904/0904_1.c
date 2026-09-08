#include <stdio.h>
#include <math.h>

//이동 로봇 바퀴 오차율에 따른 편류각 및 편류 거리

int main(void)
{
    double r, W, e_L, e_R, L, N;                        //변수 선언
    double r_l, D_l, r_r, D_r, R_c, delta, d_drift;
    const double pi = 3.141592;

    printf("바퀴 반지름 r: ");                            //변수 입력
    if (scanf("%lf", &r) != 1) return 1;
    printf("트랙폭 W: ");
    if (scanf("%lf", &W) != 1) return 1;
    printf("좌 바퀴 오차율 e_L: ");
    if (scanf("%lf", &e_L) != 1) return 1;
    printf("우 바퀴 오차율 e_R: ");
    if (scanf("%lf", &e_R) != 1) return 1;
    printf("목표 주행 거리 L: ");
    if (scanf("%lf", &L) != 1) return 1;

    if ((r<0) || (W<0) || (e_L<0) || (e_R<0) || (L<0)) return 1;

    r_l = r * (1 + e_L);                            //왼쪽 바퀴 반경
    r_r = r * (1 + e_R);                            //오른쪽 바퀴 반경
    N = L / (2 * r * pi);                           //회전수( 목표거리 / 둘레 )
    D_l = 2 * pi * r_l * N;                         //왼쪽 바퀴 유효 이동 거리
    D_r = 2 * pi * r_r * N;                         //오른쪽 바퀴 유효 이동 거리
    R_c = W * (D_l + D_r) / (2 * (D_r - D_l));      //곡률 반경
    delta = L / R_c * 180 / pi;                     //편류각
    d_drift = R_c * (1 - cos(delta));               //편류거리

    printf("\n[출력]\n");                            //결과 출력
    printf("좌/우 바퀴 반경: %.4lf m / %.4lf m\n", r_l, r_r);
    printf("곡률반경 RC = %.2lf m\n", R_c);
    printf("편류각 delta = %.2lf deg\n", delta);
    printf("편류거리 d_drift = %.2lf m\n", d_drift);
}