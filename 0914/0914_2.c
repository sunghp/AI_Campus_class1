#include <stdio.h>

typedef struct                              //위치 구조체 선언
{
    double x;
    double y;
} position;

void move(position *p);

int main(void)
{  
    position bot;                               //변수 선언
    int i, N;

    bot.x = 0.0;                                //초기 위치 초기화
    bot.y = 0.0;
    printf("로봇 위치: (x: %.2lf, y: %.2lf)\n", bot.x, bot.y);

    printf("움직인 횟수: ");                    //데이터 개수 입력
    scanf("%d", &N);
    for (i=0;i<N;i++)                       //n번 동안 움직인 데이터 입력
    {
        move(&bot);
        printf("로봇 위치: (x: %.2lf, y: %.2lf)\n", bot.x, bot.y);
    }

    return 0;
}

void move(position *p)                  //로봇이 움직이는 함수
{   
    double  dx, dy;
    printf("x좌표로 움직이는 인코더: ");    //1024인코더로 나누어 바퀴수 계산
    scanf("%lf", &dx);
    dx = dx / 1024.00;
    printf("y좌표로 움직이는 인코더: ");
    scanf("%lf", &dy);
    dy = dy / 1024.00;

    p->x = p->x + dx;                   //구조체 포인터 연산
    p->y = p->y + dy;
}