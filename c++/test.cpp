#include"iostream"
#include"string"
#include"string.h"
using namespace std;
int count(char *substr,char *str){
    int num,len;
    len=strlen(substr);
    char *p;
    if(len<1)
        return -1;
    for(num=0,p=str;;){
        p=strstr(p,substr);//strstr，在参数1中找到参数2并把其在1中的起始位置返回
        if(p!=NULL){  //c++的空用大写NULL
            num++;
            p+=len;//找到之后，次数加一，p后移len个单位
        }else
            break;
    }
    return num;
}
int main(){
    string a="ha",b="hahadwha";
    cout<<count(&a[0],&b[0]);
}