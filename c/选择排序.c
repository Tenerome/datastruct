#include<stdio.h>
int main()
{
	void swap(int *x,int *y);
	int a[5]={1,5,6,4,8},i,j,t;
	for(i=1;i<=4;i++)
		for(j=0;j<=i-1;j++)
			if(a[i]<a[j])
				swap(&a[i],&a[j]);
	for(i=0;i<=4;i++)
		printf("%d\n",a[i]);
}
void swap(int *x,int *y)
{
	int t;
	t=*x;
	*x=*y;
	*y=t;
}