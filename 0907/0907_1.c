#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//랜덤 데이터 로그에서 급가속/급제동 이벤트 카운트
/*로봇(또는 자율주행 차량)의 속도 로그 데이터를 배열로 입력받아,
이웃한 시점 간의 속도 변화량을 계산하여 급가속 또는 급제동 횟수를 계산한다.
단, 실제 주행의 현실을 반영하여 10개 이상의 데이터가 일정한 방향성을 유지하고 
속도는 0~200의 한계를 두었다. */

int main(void)
{
    int N, idx, cnt;                             //변수 선언
    int pred_v, v, next_v, dir, sign;
    int i, j;
    int acc = 0, stop = 0;

    printf("데이터의 개수를 입력하세요: ");     //N 입력
    scanf("%d", &N); 
    pred_v = 0;                            //변수 초기화
    idx = 0;
    cnt = 20 * N;
    
    int speed[cnt];

    srand(time(NULL));                     //랜덤 시드 초기화
    for (i=0; i<N; i++)
    {
        sign = rand() % 2;               //부호 결정(0 or 1), 0이면 가속, 1이면 감속
        dir = rand() % 11 + 10;          //방향이 유지되는 개수(10 ~ 20)
        for (j=0; j<dir; j++)
        {
            v = rand() % 11;                        //속도 변화(0 ~ 10)
            if (sign == 0) next_v = pred_v + v;     //다음 속도 = 이전 속도 +- 10
            if (sign == 1) next_v = pred_v - v;
            if (next_v <=0) next_v = 0;             //음수 0 처리
            if (next_v >=200) next_v = 200;         //최대 속도 200 처리
            speed[idx] = next_v;                    //배열에 삽입
            pred_v = next_v;                        //지금 속도를 이전 속도에 대입
            if (v >= 10 && sign == 0) acc++;        //급가속 및 급감속 카운트
            if (v >= 10 && sign == 1) stop++;
            idx++;
            if (idx >= cnt) break;
        }
    }
    for(i=0; i<(idx); i++)                //결과 출력
    {
        printf("%d ", speed[i]);
    }
    printf("\n");
    printf("acc: %d\n", acc);
    printf("stop: %d\n", stop);

    return 0;
}