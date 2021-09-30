#include<stdio.h>
int main()
{
int a[8]={1,2,3,4,5,6,7,8},r=7,l=0,m,s;
scanf("%d",&s);
while(l<=r)
{
	m=(r+l)/2;
	if(a[m]==s)
	{
		printf("%d",m);
	    break;
	}
	else if(a[m]<s)
		l=m+1;
	else
		r=m-1;
}
}