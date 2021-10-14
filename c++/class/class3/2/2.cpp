#include<iostream>
#include<string>
using namespace std;
#include "2.h"
extern int num;
extern string name;
extern char sex;
void A::setValue(){
    cin>>num;
    cin>>name;
    cin>>sex;
}

void A::display(){
    cout<<"num:"<<num<<endl;
    cout<<"name:"<<name<<endl;
    cout<<"sex:"<<sex<<endl;
}
