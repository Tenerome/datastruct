#include<stdio.h>
#include<malloc.h>
#define Maxsize 100
typedef char ElemType;
typedef struct
{ ElemType data[Maxsize];
 int top;//栈顶指针
}SqStack;
void InitStack(SqStack *&s)//初始化栈s
{
 s=(SqStack*)malloc(sizeof(SqStack));
 s->top=-1;//栈顶指针初始值为-1
}
void DestroyStack(SqStack *&s)//销毁栈s
{
 free(s);
}
bool StackEmpty(SqStack *s)//判断栈s是否为空
{
 return(s->top==-1);
}
bool Puch(SqStack *&s,ElemType e)//进栈
{
 if(s->top==Maxsize-1)//栈满的情况
  return false;
 else
  s->top++;//栈顶指针加一
  s->data[s->top]=e;//把元素e放到栈顶指针处
 return true;
}
bool Pop(SqStack *&s,ElemType &e)//出栈
{
 if(s->top==-1)//栈为空时候的情况
  return false;
 else
  e=s->data[s->top];
 s->top--;
 return true;
}
bool GetTop(SqStack *&s,ElemType &e)//取栈顶元素
{
 if(s->top==-1)//栈为空的情况
  return false;
 else
  e=s->data[s->top];
 return true;
}
int main()
{
 char a,b,c,d,m;
 ElemType e;
 SqStack *s;
 InitStack(s);
 printf("初始化栈成功s\n");
 printf("判断\n");
 printf("栈为%s\n",(StackEmpty(s)?"空":"非空"));
 printf("输入元素a-e\n");
 scanf("%c %c %c %c %c%*c",&a,&b,&c,&d,&m);
 Puch(s,a);
 Puch(s,b);
 Puch(s,c);
 Puch(s,d);
 Puch(s,m);
 printf("判断\n");
 printf("栈为%s\n",(StackEmpty(s)?"空":"非空"));
 printf("出栈；");
 while(!StackEmpty(s))
  {
   Pop(s,e);
   printf("%c",e);
  }
 printf("\n");
 printf("判断\n");
 printf("栈为%s\n",(StackEmpty (s)?"空":"非空"));
 printf("释放栈\n") ;
 DestroyStack(s);
 return 0;
}
