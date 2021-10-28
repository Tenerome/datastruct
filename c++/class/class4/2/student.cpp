#include"iostream"
using namespace std;
class student{
    int sno,grade;
    public:
    int getSno();
    int getGrade();
    void print();
    student(int,int);
};

int student::getSno(){
    return this->sno;
}
int student::getGrade(){
    return this->grade;
}
void student::print(){
    cout<<"学号:"<<sno<<endl<<"成绩:"<<grade<<endl;
}
student::student(int sno,int grade){
    this->sno=sno;
    this->grade=grade;
}

student Max(student *p){
    int max=(*p).getGrade();
    student maxstu=*p;
    while ((*p).getSno())
    {
        if((*p).getGrade()>max)
        {
             max=(*p).getGrade();
             maxstu=*p;
        }
        p++;
    }
    return maxstu;
    
}
    
int main(){
    student stu[5]={
        student(1,90),
        student(2,98),
        student(3,100),
        student(4,89),
        student(5,93)
    };
    cout<<"成绩最高的是:"<<Max(stu).getSno()<<endl<<Max(stu).getGrade();
}

