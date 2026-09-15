#include <stdio.h>
#include <string.h>
//fast.log에서 각 시간대 별로 핑을 한 횟수, 가장 핑을 많이 한 주소 3개, 총 핑 횟수(IPv4, IPv6의 특징 구분)를 출력

void bub_sort(char add[][50], int *, int);          //주소 3개를 찾기 위한 버블 정렬

int main(void)
{
    FILE *ifp, *ofp;                                            //변수 선언
    int i, digit, time[25]={0}, del=2, cnt_add[20]={0};
    char str[1000], p[20][50]={0}, add[50];
    char *res, *now;
    int cnt = 0, N = 1;

    ifp = fopen("fast.log", "r");                           //파일 오픈
    if (ifp == NULL)                                        //예외 처리
    {
        printf("파일을 입력받지 못했습니다.\n");
        return 1;
    }
    while (1)
    {
        res = fgets(str, sizeof(str), ifp);                 //NULL을 받을 때까지 한 줄씩 처리
        if (res == NULL)
        {
            break;
        }
        if (strstr(res, "{IPv6-ICMP}")!=NULL)                   //IPv6일때 일반 처리
        {
            cnt++;                                                //총 핑 횟수를 위한 ++
            now = strstr(res, "/2025");                             //해당 핑의 시간 찾기
            digit = (int)((now[6]-'0')*10 + (now[7]-'0'));          //10의 자리, 1의 자리 문자로 받아 정수로 변환
            time[digit]++;                                          //time배열에 파싱
            strncpy(add, strstr(res, "->")-9, 4);                   //해당 핑의 주소 찾아 add 문자열에 복사
        }
        else if (strstr(res, "{ICMP}")!=NULL)                   //IPv4일때 2번마다 1번 처리
            del++;
            if (del % 2 == 1){
                {
                    cnt++;                                              //위와 동일
                    now = strstr(res, "/2025");
                    digit = (int)((now[6]-'0')*10 + (now[7]-'0'));
                    time[digit]++;
                    strncpy(add, strstr(res, "->")-7, 4);
                }
            }
        for (i=0; i<N; i++) {                               //p 문자열 배열을 돌면서 add와 같은 문자열이 있는지 확인
            if (strcmp(add, p[i])==0) {                     //있으면 해당 인덱스 +1
                cnt_add[i]++;
                break;
            }
        }
        if (i == N) {                                       //끝까지 없으면 문자열을 추가하고 해당 인덱스 +1, 배열 크기 +1
            strcpy(p[N], add);
            cnt_add[N] = 1;
            N++;
        }
    }
    bub_sort(p, cnt_add, N);                                //주소 문자열 배열 버블 정렬(문자열 배열, 인덱스 배열, 배열 크기)

    printf("=============================================================================================================\n");      //결과 출력
    printf("[결과 출력]\n");
    printf("[시간대 별 핑 횟수]\n");
    printf("1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24\n");
    for (i=1;i<25;i++)
    {
        printf("%-4d", time[i]);
    }
    printf("\n\n[가장 많이 핑을 한 주소 top 3와 각 핑 횟수]\n");
    printf("[주소]    [횟수]\n");
    for (i=0;i<3;i++)
    {
        printf(" %s       %d\n", p[i], cnt_add[i]);
    }
    printf("\n[총 핑의 횟수]: %d\n", cnt);
    printf("=============================================================================================================\n");

    fclose(ifp);

    return 0;
}

void bub_sort(char add[][50], int *add_cnt, int N)                                //버블 정렬
{
    int i, j;
    for (i=N;i>0;i--)
    {
        for (j=0;j<i;j++)
        {
            if (add_cnt[j] < add_cnt[j+1])                              //인덱스 배열을 기준으로 버블 정렬
            {
                int temp = add_cnt[j];                                  //해당되는 인덱스 배열의 위치 교환
                add_cnt[j] = add_cnt[j+1];
                add_cnt[j+1] = temp;

                char temp_str[50];                                      //해당되는 문자열 배열의 위치 교환
                strcpy(temp_str, add[j]);
                strcpy(add[j], add[j+1]);
                strcpy(add[j+1], temp_str);
            }
        }
    }
}
