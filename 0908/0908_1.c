#include <stdio.h>


//360도 라이다에서 최소거리 / 방향 찾기 (스캔 데이터 수기로 직접 입력)

int main(void)
{   
    int i, N, min_idx = 0;                          //변수 입력
    double degree, min = 500;

    printf("스캔 데이터 개수 입력 : ");                     //데이터 개수 입력(데이터 사이 각도 : 360 / N)
    scanf("%d", &N);
    double dist[N];
    printf("스캔 데이터 입력(0~500cm, %d개 입력): ", N);    //각도 별 거리 입력
    for(i=0; i<N; i++)
    {
        scanf("%lf", &dist[i]);
        if (dist[i] < min)                              //최소 거리 및 각도 저장
        {
            min = dist[i];
            min_idx = i;
        }
    }
    degree = min_idx * 360 / N;

    printf("최소 거리: %.2lf\n", min);          
    printf("각도: %.2lf\n", degree);

    return 0;
}