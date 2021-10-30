//第三章 7.4
#include"iostream"
using namespace std;
class Student{
    mutable int num;
    mutable float score;
    public:
    Student(int n,float s):num(n),score(s){};
    void change(int n,float s) const{
        num=n;
        score=s;
    }

    void display() const{
        cout<<num<<" "<<score<<endl;
    }

};
int main(){
    const Student stud(101,78.5);
    const Student *p=&stud;
    p->display();
    p->change(101,80.5);
    p->display();
}