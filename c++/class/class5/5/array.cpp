//第四章 5
#include"iostream"
using namespace std;
class array{
    int a[6],i;
    public:
    array();
    array operator+(array &);
    void operator<<(int);
    void operator>>(int);
    void disp();
    int * get();
    
};
array::array(){
    for(i=0;i<=5;i++)
        a[i]=0;
}
 array array::operator+(array &aa){
     for(i=0;i<=5;i++)
        *(aa.get()+i)+=*(get()+i);
    return aa;
 }
 void array::operator<<(int s){
    for(i=0;i<=5;i++){
        cout<<a[i]<<" ";
        if((i+1)%3==0)
            cout<<endl;
    }
 }
 void array::operator>>(int s){
     cout<<"请输入第一行:";
     for(i=0;i<=2;i++)
         cin>>a[i];
     cout<<"请输入第二行:";
     for(i=3;i<=5;i++)
         cin>>a[i];
     
 }
int * array::get(){
    return a;
}

int main(){
    array a1,a2,a3;
    cout<<"a1:"<<endl;
    a1>>1;
    cout<<"a2:"<<endl;
    a2>>1;
    a3=a1+a2;
    cout<<"a3:"<<endl;
    a3<<1;
    
}