//8
#include"iostream"
using namespace std;
class Student{
    int num;
    float score;
    public:
    Student(int n,float s):num(n),score(s){};
    void change(int n,float s){
        num=n;
        score=s;
    }
    void display(){
        cout<<num<<" "<<score<<endl;
    }

};
void fun(Student &stud){
    stud.display();
    stud.change(101,80.5);
    stud.display();
}

int main(){
    Student stud(101,78.5);
    fun(stud);
}