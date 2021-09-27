#include<iostream>
using namespace std;
int maxdivisor(int x,int y){//辗转相除法
    int z = y;
	while(x%y!=0)
	{
		z = x%y;
		x = y;
		y = z;	
	}
	return z;

}
int main(){
    int a[8]={26,1007,956,705,574,371,416,517},b[8]={994,631,772,201,262,763,1000,781},c[8];
    for(int i=0;i<8;i++)
        c[i]=maxdivisor(a[i],b[i]);
    cout<<"max divisor array:";
    for(int i=0;i<8;i++)
        cout<<c[i]<<" ";
}