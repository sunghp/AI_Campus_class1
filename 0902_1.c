#include <stdio.h>

int main(void) 
{
    int a;          // 변수 선언
    int b, c;
    double da;
    char ch;

    a = 10;         // 변수 초기화
    b = a;
    c = a + 20;
    a = 20;
    c = a + 20;
    da = 3.5;
    ch = 'A';   

    printf("변수 a의 값: %d\n", a);        // 변수 값 출력
    printf("변수 b의 값: %d\n", b);
    printf("변수 c의 값: %d\n", c);
    printf("변수 da의 값: %.1f\n", da);
    printf("변수 ch의 값: %c\n", ch);

    return 0;
}