#include <stdio.h>

//배터리 잔량 히스테리시스 경보 시스템
/*배터리 잔량(%) 로그를 배열로 입력받아, 잔량이 특정 임계값 이하로 떨어지면 경고를 발생시키고,
다시 일정 수준 이상으로 회복될 때까지 경고를 유지하여 불필요한 경고 깜박임을 억제한다.*/

int main(void)
{
    int N, bat, i, alarm;                   //변수 선언

    printf("데이터 개수를 입력하세요: ");        //데이터 개수 
    scanf("%d", &N);
    alarm = 0;
    for (i=0; i<N+1; i++)
    {
        printf("배터리 잔량을 입력하세요(%d/%d): ", i+1, N+1);  //배터리 잔량 직접 입력
        scanf("%d", &bat);
        if (alarm == 0 && bat <= 30) alarm = 1;         //히스테리시스 적용
        if (alarm == 1 && bat >= 35) alarm = 0;
        printf("현재 배터리 잔량: %d\n", bat);              //알람 출력
        if (alarm == 0) printf("경고 알람 : OFF\n");
        if (alarm == 1) printf("경고 알람 : ON\n");
    }

    return 0;
}