//第三章11
#include"iostream"
using namespace std;
class Date;
class Time{
    int hour,minute,sec;
    public:
    Time(int,int,int);
    void display(Date &);
};
class Date{
    int year,month,day;
    public:
    Date(int,int,int);
    friend class Time;
};

Time::Time(int hour,int minute,int sec){
    this->hour=hour;
    this->minute=minute;
    this->sec=sec;
}
void Time::display(Date &d){
    cout<<d.year<<"年"<<d.month<<"月"<<d.day<<"日"<<endl;
    cout<<hour<<":"<<minute<<":"<<sec<<endl;
}
Date::Date(int year,int month,int day){
    this->year=year;
    this->month=month;
    this->day=day;
}
int main(){
    Time t1(10,13,56);
    Date d1(2004,1,1);
    t1.display(d1);
}