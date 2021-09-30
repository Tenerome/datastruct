#include<iostream>
using namespace std;
int main(){
int a[3][3],i,j,sum=0;
float avg;
cout<<"input:";
for(i=0;i<=2;i++)
    for(j=0;j<=2;j++)
        cin>>a[i][j];
for(i=0;i<=2;i++)
    for(j=0;j<=2;j++)
        sum=sum+a[i][j];

avg=sum/9.0;
cout<<"output:"<<sum<<endl<<avg<<endl;
}
