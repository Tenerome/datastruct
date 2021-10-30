//第三章 10
#include"iostream"
using namespace std;
class Date;
class Time{
    int hour,minute,sec;
    public:
    Time(int,int,int);
    friend void display(Date &d,Time &t);
};
class Date{
    int year,month,day;
    public:
    Date(int,int,int);
    friend void display(Date &d,Time &t);
};

Time::Time(int hour,int minute,int sec){
    this->hour=hour;
    this->minute=minute;
    this->sec=sec;
}
Date::Date(int year,int month,int day){
    this->year=year;
    this->month=month;
    this->day=day;
}

void display(Date &d,Time &t){
    cout<<d.year<<"年"<<d.month<<"月"<<d.day<<"日"<<endl;
    cout<<t.hour<<":"<<t.minute<<":"<<t.sec<<endl;
}
int main(){
    Time t1(10,13,56);
    Date d1(2004,1,1);
    display(d1,t1);
}