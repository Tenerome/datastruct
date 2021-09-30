#include<iostream>
using namespace std;
int main(){
int i,a,b,c;
for(i=100;i<1000;i++)
{
    a=i/100;
    b=(i-a*100)/10;
    c=i-a*100-b*10;
    if(a*a*a+b*b*b+c*c*c==i)
        cout<<i<<endl;
}
}
