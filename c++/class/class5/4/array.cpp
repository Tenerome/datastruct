//第四章 4
//构造函数的参数类型只能初始化对应类型的成员
#include"iostream"
using namespace std;
class array{
    int a[6],i;
    public:
    array();
    array(int[]);
    array operator+(array &);
    void disp();
    int * get();
};
array::array(){
    for(i=0;i<=5;i++)
        a[i]=0;
}
array::array(int b[]){
    for(i=0;i<=5;i++)
        a[i]=b[i];
}
 array array::operator+(array &aa){
     for(i=0;i<=5;i++)
        *(aa.get()+i)+=*(get()+i);
    return aa;
 }
void array::disp(){
    for(i=0;i<=5;i++){
        cout<<a[i]<<" ";
        if((i+1)%3==0)
            cout<<endl;
    }
}
int * array::get(){
    return a;
}
int main(){
    int c1[6]={1,2,3,4,5,6};
    int c2[6]={6,5,4,3,2,1};
    array a1(c1),a2(c2),a3;
    cout<<"a1:"<<endl;
    a1.disp();
    cout<<"a2:"<<endl;
    a2.disp();
    a3=a1+a2;
    cout<<"a3:"<<endl;
    a3.disp();
}