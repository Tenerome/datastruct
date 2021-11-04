#include"iostream"
using namespace std;

class student{
int num;
string name,sex;
public:
student();
student(int,string,string);
void disp();
friend class teacher;
};
class teacher{
int num;
string name,sex;
public:
teacher();
teacher(int,string,string);
void disp();
teacher operator%(student &);
};

student::student(){
    num=0;
    name="张三";
    sex="男";
}
student::student(int num,string name,string sex){
    this->name=name;
    this->num=num;
    this->sex=sex;
}
void student::disp(){
    cout<<"学生信息:"<<endl;
    cout<<"学号:"<<num<<endl<<"姓名:"<<name<<endl<<"性别:"<<sex<<endl;
}

teacher::teacher(){
    num=0;
    name="张三";
    sex="男";
}
teacher::teacher(int num,string name,string sex){
    this->name=name;
    this->num=num;
    this->sex=sex;
}
teacher teacher::operator%(student &stu){
    teacher t;
    t.num=stu.num;
    t.name=stu.name;
    t.sex=stu.sex;
    return t;
}
void teacher::disp(){
    cout<<"教师信息:"<<endl;
    cout<<"工号:"<<num<<endl<<"姓名:"<<name<<endl<<"性别:"<<sex<<endl;
}

int main(){
    student stu(1023,"胡图图","男");
    stu.disp();
    teacher teac;
    teac=teac%stu;
    teac.disp();
}