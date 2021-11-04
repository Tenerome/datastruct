//第四章 3
#include"iostream"
using namespace std;

class complex{
    int a,b;
    public:
    complex();
    complex(int,int);
    void disp();

    complex operator+(complex &);
    complex operator+(int);
    friend complex operator+(int,complex&);

};
    complex::complex(){
        this->a=0;
        this->b=0;
    }
    complex::complex(int a,int b){
        this->a=a;
        this->b=b;
    }
    complex complex::operator+(complex &c){
        return complex(a+c.a,b+c.b);
    }
    complex complex::operator+(int a){
        return complex(this->a+a,this->b);
    }
   void  complex::disp(){
       cout<<a<<"+"<<b<<"i"<<endl;
   }

complex operator+(int a,complex &c){
    return complex(c.a+a,c.b);
}
int main(){
    complex c1(2,3),c2(2,5),c3,c4,c5;
    c3=c1+c2;
    c4=c1+2;
    c5=1+c2;
    
    c3.disp();
    c4.disp();
    c5.disp();

}