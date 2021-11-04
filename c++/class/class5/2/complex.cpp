//第四章 2
#include"iostream"
using namespace std;

class complex{
    double a,b;
    public:
    complex();
    complex(int,int);
    complex operator+(complex &);
    complex operator-(complex &);
    complex operator*(complex &);
    complex operator/(complex &);
    void disp();

};
    complex::complex(){
        this->a=0;
        this->b=0;
    }
    complex::complex(int a,int b){
        this->a=a;
        this->b=b;
    }
   void  complex::disp(){
       cout<<a<<"+"<<"("<<b<<"i"<<")"<<endl;
   }
   complex complex::operator+(complex &c){
     return complex(a+c.a,b+c.b);
   }
   complex complex::operator-(complex &c){
     return complex(a-c.a,b-c.b);
   }
   complex complex::operator*(complex &c){
     return complex(a*c.a-b*c.b,a*c.b+b*c.a);
   }
   complex complex::operator/(complex &c){
     complex cc;
     cc.a=(a*c.a+b*c.b)/(c.a*c.a+c.b*c.b);
     cc.b=(b*c.a-a*c.b)/(c.a*c.a+c.b*c.b);
     return cc;
   }

int main(){
    complex c1(1,3),c2(2,5),c3,c4,c5,c6;
    c3=c1+c2;
    c4=c1-c2;
    c5=c1*c2;
    c6=c1/c2;
    c3.disp();
    c4.disp();
    c5.disp();
    c6.disp();

}