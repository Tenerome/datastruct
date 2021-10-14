#include<iostream>
using namespace std;
class Time{
    int hour,minute,sec;
    public:
    void setTime(){
        cin>>hour>>minute>>sec;
    }
    void printTime(){
        cout<<hour<<":"<<minute<<":"<<sec<<endl;
    }
};
int main(){
    Time t;
    t.setTime();
    t.printTime();
}
