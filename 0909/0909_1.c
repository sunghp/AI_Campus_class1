#include <stdio.h>

void my_strsort(char *str1, char *str2, char *str3);
int my_strcmp(char *str1, char *str2);
//직접 str함수 만들기

int main(void)
{
    char str1[80], str2[80], str3[80];  //세 개의 문자열 선언 및 입력
    scanf("%s%s%s", str1, str2, str3);
    my_strsort(str1, str2, str3);

    return 0;
}

void my_strsort(char *str1, char *str2, char *str3)         //세 개의 문자열을 사전순으로 출력하는 strsort 함수
{
    char *min, *max, *mid;

    if (my_strcmp(str1, str2)>0){               //str1이 str2보다 나중에 옴
        if (my_strcmp(str3, str1)>0)               //str3이 str1보다 나중에 옴: str3 > str1 > str2
        {
            max = str3;
            mid = str1;
            min = str2;
        }
        else if (my_strcmp(str2, str3)>=0)              //str2이 str3보다 나중에 옴: str1 > str2 > str3
        {
            max = str1;
            mid = str2;
            min = str3;
        }
        else                                    //str1 > str3 > str2
        {
            max = str1;
            mid = str3;
            min = str2;
        }
    }
    else{                                   //str2가 str1보다 같거나 나중에 옴
        if (my_strcmp(str3, str2)>0)               //str3이 str2보다 나중에 옴: str3 > str2 > str1
        {
            max = str3;
            mid = str2;
            min = str1;
        }
        else if (my_strcmp(str1, str3)>=0)              //str1이 str3보다 나중에 옴: str2 > str1 > str3
        {
            max = str2;
            mid = str1;
            min = str3;
        }
        else                                    //str2 > str3 > str1
        {
            max = str2;
            mid = str3;
            min = str1;
        }
    }
    printf("사전적으로 가장 먼저 오는 문자열: %s\n", min);
    printf("사전적으로 두번째로 오는 문자열: %s\n", mid);
    printf("사전적으로 가장 나중에 오는 문자열: %s\n", max);
    
}

int my_strcmp(char *str1, char *str2)       //문자열 두개를 받아 사전순으로 앞 문자열이 나중에 오면 1, 먼저오면 -1, 같으면 0을 출력
{
    int i = 0;
    while(str1[i] == str2[i])               //\0이 나올때까지 같으면 0출력
    {
        if (str1[i] == '\0') return 0;
        i++;

    }
    if (str1[i] > str2[i]) return 1;    //값이 다를때 비교
    if (str1[i] < str2[i]) return -1;   //값이 다를때 비교
}