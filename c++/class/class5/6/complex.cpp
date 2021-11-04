//第四章 6
#include"iostream"
using namespace std;

class complex{
    double a,b;
    public:
    complex();
    complex(double,double);
    void disp();
    double getB(){return b;};
    double operator+(double);

};
    complex::complex(){
        this->a=0;
        this->b=0;
    }
    complex::complex(double a,double b){
        this->a=a;
        this->b=b;
    }
   double complex::operator+(double s){
       return a+s;
   }

   void  complex::disp(){
       cout<<a<<"+"<<b<<"i"<<endl;
   }

int main(){
    complex c1(2,3);
    double x=9,y;
    y=c1+x;
    cout<<"y="<<y<<endl;
    complex c2(y,c1.getB());
    c2.disp();
    
}