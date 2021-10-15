#include"6.h"
#include"iostream"
using namespace std;

Personnel::Personnel(){
   num=0;
   name="姓名";
   sex="性别";
}
Personnel::Personnel(const Personnel &another){
  num=another.num;
  name=another.name;
  sex=another.sex;
}

void Personnel::prin(){
    cout<<"编号:"<<num<<endl;
    cout<<"姓名:"<<name<<endl;
    cout<<"性别:"<<sex<<endl;
}
void Personnel::input(int num,string name,string sex){
  this->num=num;
  this->name=name;
  this->sex=sex;

}
