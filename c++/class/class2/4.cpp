//todo  怎么输入输出不确定长度的数组，指针
#include<iostream>
#define  Max 100000;
using namespace std;

int length(int *p)
{ //获取数组长度函数
    int len;
    while (*p)
    {
        p++;
        len++;
    }
    return len;
}
void prin(int a[],int len){
    for(int i=0;i<len;i++)
        cout<<*(p+i);
}
void sort(int *p){
    int i=0;
    while(*p){
    while(*(p+i)){
        if(*p==*(p+i))
        *(p+i)=Max;
    }
    p++;
    }
}
int main(){
    int a[6]={1,2,2,1,2,2},b,i=0;
    int len=length(a);
    //  while (1)
    // {
    //     cin>>b;
    //     if(b<0)
    //         break;
    //     else
    //         a[i++]=b;
       
    // }
    prin(a,len);
    // sort(a);
    // prin(a);
    
}