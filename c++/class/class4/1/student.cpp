#include"iostream"
using namespace std;
class student{
    int sno,grade;
    public:
    void print();
    student(int,int);
};

void student::print(){
    cout<<"学号:"<<sno<<endl<<"成绩:"<<grade<<endl;
}
student::student(int sno,int grade){
    this->sno=sno;
    this->grade=grade;
}

int main(){
    student stu[5]={
        student(1,90),
        student(2,98),
        student(3,100),
        student(4,89),
        student(5,93)
    };
    student *p=stu;
    (*p).print();
    (*(p+2)).print();
    (*(p+4)).print();
}

