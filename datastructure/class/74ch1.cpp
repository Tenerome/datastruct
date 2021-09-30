#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SizeMax 10
typedef char ElemType;
typedef struct
{
    ElemType data[SizeMax];
    int length;
 } SqList;
void InitList(SqList *&L)
 {
	L=(SqList *)malloc(sizeof(SqList));
	L->length=0;
}
void Insert(SqList *&L,ElemType s)
 {
	L->data[L->length]=s;
	L->length++;
}
void Print(SqList *&L)
{
	int i;
	printf("输出顺序表为：\n");
	for(i=0;i<L->length-1;i++)
	printf("%c ",L->data[i]);
	printf("%c\n",L->data[L->length-1]);
 }
void PrintLength(SqList *&L)
{
    printf("顺序表的长度为：");
	printf("%d\n",L->length);
 }
bool SqNull(SqList *&L)
{
	if(L->length)return 1; return 0;
}
void PrintData(SqList *&L,int n)
{
    printf("表第三个元素为：");
	printf("%c\n",L->data[n-1]);
}
bool Find(SqList *&L,char a)
{
	int i;
	for(i=0;i<L->length;i++)
		if(L->data[i]==a)
		return i+1;
 }
void Insertinto(SqList *&L,int n,char f)
{
	int j;
	n--;
	for(j=L->length;j>n;j--)
		L->data[j]=L->data[j-1];
		L->data[n]=f; L->length++;
}
void Delete(SqList *&L,int n)
{
	int j;
	n--;
	for(j=n;j<L->length;j++)
	L->data[j]=L->data[j+1];
	L->length--;
}
int main()
{
	SqList *L;
	InitList(L); //初始化顺序表
	ElemType a,b,c,d,e;
	printf("输入a-e\n");
	scanf("%c %c %c %c %c%*c",&a,&b,&c,&d,&e);
	Insert(L,a);
	Insert(L,b);
	Insert(L,c);
	Insert(L,d);
	Insert(L,e); //使用尾插法插入元素a,b,c,d,e
	Print(L); //输出顺序表
	PrintLength(L); //输出顺序表长度
	if(SqNull(L))
		printf("顺序表不为空\n");
	else
		printf("顺序表为空\n"); //判断顺序表是否为空
	PrintData(L,3); //输出第三个元素
	printf("元素a的位置：%d\n",Find(L,a)); //输出元素a的位置
	printf("输入元素f\n");
	ElemType f;
	scanf("%c",&f);
	Insertinto(L,4,f); //将f插入到第四个位置
	Print(L); //输出顺序表
	Delete(L,3); //删除第三个元素
	printf("删除第三个元素后");
	Print(L); //输出顺序表
	free(L); //释放内存
	return 0;
 }
