#include <stdio.h>

void normalize(double *, double *, int, double, double, double, double);
//센서값 정규화
//로봇의 각 센서는 센서 종류에 따라 값의 범위가 다르다. 이런 센서값을 제어 시스템에서 같은 기준으로 사용하기 위해 함수와 포인터를 사용하여 일정한 비율로 정규화한다.

int main(void)
{
    int i, N;                                                  //변수 선언
    double min_in, max_in, min_out, max_out;
    printf("데이터 개수(N) 입력: ");
    scanf("%d", &N);
    double dat[N], norm[N];
    printf("센서 입력값: ");                                   //변수 입력
    for (i=0; i<N; i++)
    {
        scanf("%lf", &dat[i]);                              //센서값 입력
    }
    printf("입력 범위: ");                                    //센서 입력 범위 설정(min_in, max_in)
    scanf("%lf%lf", &min_in, &max_in);
    printf("출력 범위: ");                                    //정규화 범위 설정(min_out, max_out)
    scanf("%lf%lf", &min_out, &max_out);

    normalize(dat, norm, N, min_in, max_in, min_out, max_out);   //정규화 계산(원본 배열, 정규화 값의 배열, 입력 출력의 범위 값 전달)

    printf("\n[정규화 결과]\n");                                                    //결과 출력
    for (i=0;i<N;i++)
    {
        printf("센서[%d] = %-6.1lf -> 정규화 = %-6.1lf\n", i+1, dat[i], norm[i]);
    }

    return 0;
}

void normalize(double *x, double *y, int N, double min_in, double max_in, double min_out, double max_out)
{
    int i;
    for (i=0; i<N; i++)
    {
        *(y+i) = (*(x+i) - min_in) * (max_out - min_out) / (max_in - min_in) + min_out;     //각 배열의 인덱스에 맞게 정규화 한 값 삽입
    }
}