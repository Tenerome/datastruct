#include<stdio.h>
int main()
{
	int i,j,a[8]={5,13,1,8,15,6,4,55},min,k;
	for(i=0;i<=6;i++)
	{
		min=a[i];
		for(j=i+1;j<=7;j++)
		if(min>a[j]);
		{
			min=a[j];
			k=j;
		}
		a[k]=a[i];
		a[i]=min;
	}
for(i=0;i<=7;i++)

printf("%d\n",a[i]);

}
static int i;
void sum(){
	i+=i;
	if(i<=100)
		sum();
}