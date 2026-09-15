#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *ifp, *info, *warning, *error;
    char str[80];
    char *res, *comp;
    int cnt_i = 0, cnt_w= 0, cnt_e = 0;

    ifp = fopen("log.txt", "r");
    if (ifp == NULL)
    {
        printf("파일을 입력받지 못했습니다.\n");
        return 1;
    }
    info = fopen("INFO.txt", "w");
    if (info == NULL)
    {
        printf("INFO 파일을 열지 못했습니다.\n");
        return 1;
    }
    warning = fopen("WARNING.txt", "w");
    if (warning == NULL)
    {
        printf("WARNING 파일을 열지 못했습니다.\n");
        return 1;
    }
    error = fopen("ERROR.txt", "w");
    if (error == NULL)
    {
        printf("ERROR 파일을 열지 못했습니다.\n");
        return 1;
    }

    while (1)
    {
        res = fgets(str, sizeof(str), ifp);
        if (res == NULL)
        {
            break;
        }
        if (res[1]=='I') 
        {
            cnt_i++;
            fputs(res, info);
        }
        if (res[1]=='W') 
        {
            cnt_w++;
            fputs(res, warning);
        }
        if (res[1]=='E') 
        {
            cnt_e++;
            fputs(res, error);
            
        }
    }
    fprintf(info, "%d", cnt_i);
    fprintf(warning, "%d", cnt_w);
    fprintf(error, "%d", cnt_e);

    fclose(ifp);
    fclose(info);
    fclose(warning);
    fclose(error);

    return 0;
}