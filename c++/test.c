//c中没有引用变量
#include<stdio.h>
int main(){
    int a=10;
    int &b=a;
    printf("%d",b);
}