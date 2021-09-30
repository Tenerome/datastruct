#include<iostream>
using namespace std;
int main(){
int N,sum=0;
cout<<"input:";
cin>>N;
for(int i=1;i<=2*N-1;i+=2)
{
    sum=sum+i;
}
cout<<"output:"<<sum;
}

