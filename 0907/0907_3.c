#include <stdio.h>
//IR센서 반사값 임계치 분류기
/*IR 적외선 반사 센서를 이용하여 바닥에 있는 라인(검정색)을 감지하고, 
라인이 어느 방향에 위치해있는지 판단하는 프로그램*/

int main(void)
{
    int N, i;                                   //변수 선언
    int value[80], label[80];   
    int threshold;
    int black_count = 0, sum_index = 0;
    double index_avg;

    printf("N = ");                             //변수 입력(데이터 개수 N)
    if (scanf("%d", &N) != 1) return 1;
    printf("value = ");
    for (i=0; i<N; i++)
    {
        if (scanf("%d", &value[i]) != 1) return 1; //변수 입력(센서값 직접 입력)
    }
    printf("threshold = ");
    if (scanf("%d", &threshold) != 1) return 1; //변수 입력(기준 임계값(0~1023))

    for (i=0; i<N; i++)
    {
        if (value[i] < threshold) label[i] = 1;     //각 라인을 감지했는지 판별
        if (value[i] >= threshold) label[i] = 0;
        black_count += label[i];                    //라인을 감지한 센서
        sum_index += i * label[i];                  
    }
    if (black_count == 0)                   //devided by 0 에러 처리
    {
        printf("라인없음");
        return 0;
    }
    index_avg = (double)sum_index / (double)black_count; //라인 중심 위치 계산
    printf("label = ");                                  //결과 출력
    for (i=0; i<N; i++)
    {
        printf("%d ", label[i]);
    }
    printf("\n");
    printf("black_count = %d\n", black_count);
    printf("index_avg = %.2lf\n", index_avg);

    return 0;
}