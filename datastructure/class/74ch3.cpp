#include "stdio.h"
#include "string.h"
#define size 100

typedef struct
{
	char data[size];
	int len;
}String;

String a,b,c,d,e;
void scan(String &s,char arg[])//录入，&s 直接修改
{
	int i;//定义在外面因为循环之后i就是length
	for(i=0;arg[i]!='\0';i++)
		s.data[i]=arg[i];
	s.len=i;
}

void prin(String s)//输出
{
	for(int i=0;i<s.len;i++)
		printf("%c",s.data[i]);
	printf("\n");
}

void encrypt()//加密
{
int i;
for(i=0; i<c.len; i++)
	for(int j=0; j<a.len; j++)
			if(c.data[i]==a.data[j])
				d.data[i]=b.data[j];
d.len=i;
}


void unencry()//解密
{
int i;
for(i=0; i<d.len; i++)
	  for(int j=0; j<b.len; j++)
		if(d.data[i]==b.data[j])
			e.data[i]=a.data[j];
e.len=i;
}

int main()
{
	scan(a,"abcdefghijklmnopqrstuvwxyz");
	scan(b,"ngzqtcobmuhelkpdawxfyivrsj");
	char st[size];
	printf("输入待加密文本：\n");
	gets(st);
	scan(c,st);
	printf("加密文本：\n");
	encrypt();
	prin(d);
	printf("解密文本：\n");
	unencry();
	prin(e);
}
