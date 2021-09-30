#include<iostream>
using namespace std;
int main(){
    int a;
    cout<<"input:";
    cin>>a;
    if(a%4==0&&a%100!=0)
        cout<<"普通闰年";
    else if(a%400==0)
        cout<<"世纪闰年";
    else
        cout<<"不是闰年";
}
