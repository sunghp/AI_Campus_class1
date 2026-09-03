#include <stdio.h>

int main(void)
{
    double I_load, vel, R;
    double V, C, eta;
    double E_usable, P, t, d;
    printf("평균 전류를 입력하세요: ");
    if(scanf("%lf",&I_load)!=1) return 1;
    printf("평균 속도를 입력하세요: ");
    if(scanf("%lf",&vel)!=1) return 1;
    printf("예비율을 입력하세요: ");
    if(scanf("%lf",&R)!=1) return 1;
    printf("공칭 전압을 입력하세요: ");
    if(scanf("%lf",&V)!=1) return 1;
    printf("용량을 입력하세요: ");
    if(scanf("%lf",&C)!=1) return 1;
    printf("시스템 효율을 입력하세요: ");
    if(scanf("%lf",&eta)!=1) return 1;

    if (V<=0 || C<=0 || I_load<=0 || vel<0 || R<0 || R>1 || eta<=0 || eta>1)
    {
        printf("입력값 범위를 확인하세요\n");
        return 1;
    }

    E_usable = V * C * eta * (1 - R);
    P = V * I_load / eta;
    t = E_usable / P;
    d = vel * t;

    printf("-------사전 선정 정보-------\n");
    printf("평균전류 [A]: %.2lf\n", I_load);
    printf("평균속도 [km/h]: %.2lf\n", vel);
    printf("예비율 : %.2lf\n\n", R);

    printf("-------배터리 정보-------\n");
    printf("공칭전압 [V]: %.2lf\n", V);
    printf("용량 [Ah]: %.2lf\n", C);
    printf("시스템효율 : %.2lf\n\n", eta);

    printf("결과\n");
    printf("사용 가능 에너지: %.2lf\n", E_usable);
    printf("런타임: %.2lf\n", t);
    printf("주행거리: %.2lf\n", d);

}