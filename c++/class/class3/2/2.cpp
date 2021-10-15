#include"iostream"
#include "2.h"
using namespace std;

void A::setValue(){
    num=123;
    name="张三";
    sex="男";
}

void A::display(){
    cout<<"num:"<<num<<endl;
    cout<<"name:"<<name<<endl;
    cout<<"sex:"<<sex<<endl;
}
