#include"stdio.h"
int main(){
    float s;
    scanf("%f",&s);
    int a=s/10;
    switch (a)
    {
    case 12:
    case 11:
    case 10:
    case 9: printf("优秀");break;
    case 8: printf("良");break;
    case 7:printf("中");break;
    case 6:printf("及格");break;
    default:printf("不及格");break;
    }
}