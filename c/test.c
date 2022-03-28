#include"stdio.h"
void Q(char q);
void Q1(char q1);
// enum {low,high};

void Q(char q){
    switch(q){
        case '0':
            Q(q);
            break;
        case '1':
            Q1(q);
            break;
        default:
            printf("不接受");
    }
}
void Q1(char q1){
    switch(q1){
        case '0':
            Q(q1);
            break;
        case '1':
            printf("接受");
            break;
        default:
            printf("不接受");
    }
}
int main(){
    char q;
    scanf("%c",&q);
    Q(q);
}