#include"4.h"
#include"iostream"
using namespace std;

int main(){
    Cuboid C1,C2,C3;
    cout<<"第一个长方体:"<<endl;
    C1.setValue();
    cout<<"第二个长方体:"<<endl;
    C2.setValue();
    cout<<"第三个长方体:"<<endl;
    C3.setValue();
    C1.calculate();
    C2.calculate();
    C3.calculate();
    cout<<"第一个长方体体积:"<<endl;
    C1.prin();
    cout<<"第二个长方体体积:"<<endl; 
    C2.prin();
    cout<<"第三个长方体体积:"<<endl; 
    C3.prin();
}