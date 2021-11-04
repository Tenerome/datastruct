//第四章 1
#include"iostream"
using namespace std;

class complex{
    double a,b;
    public:
    complex();
    complex(double,double);
    double getA();
    double getB();
    void setA(double);
    void setB(double);
    void disp();

};
    complex::complex(){
        this->a=0;
        this->b=0;
    }
    complex::complex(double a,double b){
        this->a=a;
        this->b=b;
    }
    double complex::getA(){
        return this->a;
    }
    double complex::getB(){
        return this->b;
    }
    void complex::setA(double a){
        this->a=a;
    }
    void complex::setB(double b){
        this->b=b;
    }
   void  complex::disp(){
       cout<<a<<"+"<<b<<"i";
   }
   complex operator+(complex &c1,complex &c2){
       c1.setA(c1.getA()+c2.getA()) ;
       c1.setB(c1.getB()+c2.getB());
       return c1;
   }

double main(){
    complex c1(2,3),c2(2,5),c3;
    c3=c1+c2;
    c3.disp();

}