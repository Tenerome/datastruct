//goto语句

#include <stdio.h>
int main()
{
	int n,sum=0;
	n=1;
	loop:
		sum+=n;
		n++;
		if(n<=200){
			goto loop;
		}
		printf("%d\n",sum);
		return 0;
 } 