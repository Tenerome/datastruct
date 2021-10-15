#include"iostream"
using namespace std;
class Time{
    int hour,minute,sec;
    public:
    void setTime();
    void printTime();
};

 void Time::setTime(){
        cin>>hour>>minute>>sec;
    }
    void Time::printTime(){
        cout<<hour<<":"<<minute<<":"<<sec<<endl;
    }
int main(){
    Time t;
    t.setTime();
    t.printTime();
}
