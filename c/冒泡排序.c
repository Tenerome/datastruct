#include<stdio.h>
int main()
{
int a[10],i,j,t;
printf("输入10个数:");
for(i=0;i<=9;i++)
scanf("%d",&a[i]);
for(i=9;i>=1;i--)
	for(j=0;j<=i;j++)
	{
		if(a[j]>a[j+1])
		{
			t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
		}
	}
printf("排序结果:");
for(i=0;i<=9;i++)
printf("%d ",a[i]);
}