#include <stdio.h>

double calc_avg(double *arr);
int check_battery_stat(double *arr, int);

int main(void)
{
    double bat[80];
    int i, stat;
    double avg;

    printf("배터리 데이터를 입력하세요(10.0V ~ 13.0V): ");
    for (i=0; i<10; i++)
    {
        scanf("%lf", &bat[i]);
    }
    avg = calc_avg(bat);
    stat = check_battery_stat(bat, avg);
    printf("\n[결과 출력]\n");
    printf("배열 전체 데이터: ");
    for (i=0;i<10;i++)
    {
        printf("%.1lf ", bat[i]);
    }
    printf("\n평균 전압: %.1lf\n", avg);

    switch (stat)
    {
        case 1:
            printf("배터리 저하 - 전력 절약 모드 권장\n");
            break;
        case 2:
            printf("배터리 위험 - 충전 필요\n");
            break;
        default:
            printf("정상 전압 상태\n");
    }


}

double calc_avg(double *arr)
{
    int i, total = 0;
    double avg;
    for(i=0;i<10;i++)
    {
        total += arr[i];
    }
    avg = total / 10.0;

    return avg;
}

int check_battery_stat(double *arr, int avg)
{
    int i, cnt = 0;
    for (i=0;i<10;i++)
    {
        if (arr[i] < 11.0) cnt++;
    }
    if (cnt>=3) return 1;
    else if (avg<11.5) return 2;
    else return 0;
}