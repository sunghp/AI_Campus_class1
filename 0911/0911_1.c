#include <stdio.h>
#include <stdlib.h>

typedef struct{                 //점수 구조체 선언
    int num;
    char name[80];
    int kor;
    int eng;
    int math;
    int total;
    double avg;
    char grade;
} score;

char evaluate(double avg);      //학점 반환 함수 선언

void print_res(score *);        //결과 출력 함수 선언

void bub_sort(score *);         //버블 정렬 함수 선언

void swap(score *, score *);    //정렬에 필요한 swap함수 선언

int main(void)
{
    int i, j;                   //변수 선언
    int total;
    double avg;
    score list[5];
    for (i=0;i<5;i++)               //데이터 입력
    {
        printf("학번: ");
        scanf("%d", &list[i].num);
        printf("이름: ");
        scanf("%s", &list[i].name);
        printf("국어, 영어, 수학 점수: ");
        scanf("%d%d%d", &list[i].kor, &list[i].eng, &list[i].math);
        list[i].total = (list[i].kor + list[i].eng + list[i].math);
        list[i].avg = list[i].total / 3.0;
        list[i].grade = evaluate(list[i].avg);      //평균을 계산해 학점 반환
    }

    printf("# 정렬 전 데이터...\n");                    //정렬 전 결과 출력
    print_res(&list);
    
    bub_sort(&list);                                //버블 정렬

    printf("# 정렬 후 데이터...\n");                //정렬 후 결과 출력
    print_res(&list);
    
}

char evaluate(double avg){                              //학점 입력
    if (avg>=90) return 'A';
    else if (avg>=80) return 'B';
    else if (avg>=70) return 'C';
    else return 'F';
}

void swap(score *pa, score *pb)                         //구조체 값 교환
{
    score temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void bub_sort(score *list)                                //버블 정렬
{
    int i, j;
    for (i=4;i>0;i--)
    {
        for (j=0;j<i;j++)
        {
            if (list[j].total < list[j+1].total) swap(&list[j], &list[j+1]);
        }
    }
}

void print_res(score *list)                             //구조체 데이터 출력
{
    int i;
    for (i=0;i<5;i++)
    {
        printf("%5d%15s%4d%4d%4d%5d%5.1lf%3c\n", list[i].num, list[i].name, list[i].kor, list[i].eng, 
            list[i].math, list[i].total, list[i].avg, list[i].grade);
    }

}