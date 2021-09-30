#include<iostream>
#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
#define MaxWidth 40
typedef char ElemType;
typedef struct node
{
    ElemType data;//数据元素
    struct node *lchild;//指向左孩子
    struct node *rchild;//指向右孩子
}BTNode;
BTNode *create1(char *pre,char *in,int n)//由先序和中序遍历序列构造二叉树
{
    BTNode *s;
    char *p;
    int k;
    if(n<=0)return NULL;
    s=(BTNode *)malloc(sizeof(BTNode));//创建二叉树结点*s
    s->data=*pre;
    for(p=in;p<in+n;p++)//在中序序列中找等于*pre的位置k
        if(*p==*pre)
            break;
        k=p-in;
        s->lchild=create1(pre+1,in,k);
        s->rchild=create1(pre+k+1,p+1,n-k-1);
        return s;
}
BTNode *create2(char *post,char *in,int n,int m)//由中序和后序遍历序列构造二叉树
{
    BTNode *s;
    char *p,*q,*maxp;
    int maxpost,maxin,k;
    if(n<=0)return NULL;
    maxpost=-1;
    for(p=in;p<in+n;p++)//求in的全部字符中在post最右边的那个字符
        for(q=post;q<post+m;q++)//在in中用maxp指向这个字符，用maxin标志它在in中的下标
            if(*p==*q)
            {
                k=q-post;
                if(k>maxpost)
                {
                    maxpost=k;
                    maxp=p;
                    maxin=p-in;
                }
            }
    s=(BTNode *)malloc(sizeof(BTNode));//创建二叉树结点*s
    s->data=post[maxpost];
    s->lchild=create2(post,in,maxin,m);
    s->rchild=create2(post,maxp+1,n-maxin-1,m);
    return s;
}
void prin(BTNode *b)//以括号表示法输出二叉树
{
    if(b!=NULL)
    {
        printf(" %c",b->data);
        if(b->lchild!=NULL||b->rchild!=NULL)
        {
            printf("(");
            prin(b->lchild);//递归处理左子树
            if(b->rchild!=NULL)printf(",");
            prin(b->rchild);//递归处理右子树
            printf(")");
        }
    }
}
void prin1(BTNode *b)//以凹入表示法输出一颗二叉树
{
    BTNode *St[MaxSize],*p;
    int level[MaxSize][2],top=-1,n,i,width=4;
    char type;
    if(b!=NULL)
    {
        top++;
        St[top]=b;//根结点入栈
        level[top][0]=width;
        level[top][1]=2;//2表示是根
        while(top>-1)
        {
            p=St[top];//退桟并凹入显示该结点值
            n=level[top][0];
            switch(level[top][1])
            {
            case 0:type='L';break;//左结点之后输出(L)
            case 1:type='R';break;//右结点之后输出(R)
            case 2:type='B';break;//根结点之后输出(B)
            }
            for(i=1;i<=n;i++)//其中n为显示场宽，字符以右对齐显示
                printf(" ");
            printf("%c(%c)",p->data,type);
            printf("\n");
            top--;
            if(p->rchild!=NULL)
            {
                top++;//将右子树根结点入栈
                St[top]=p->rchild;
                level[top][0]=n+width;//显示场宽增width
                level[top][1]=1;//1表示是右子树
            }
            if(p->lchild!=NULL)
            {
                top++;//将左子树根结点入栈
                St[top]=p->lchild;
                level[top][0]=n+width;//显示场宽增width
                level[top][1]=0;//0表示是左子树
            }
        }
    }
}
int main()
{
    BTNode *b;
    ElemType pre[]="ABDEHJKLMNCFGI";
    ElemType in[]="DBJHLKMNEAFCGI";
    ElemType post[]="DJLNMKHEBFIGCA";
    b=create1(pre,in,14);
    printf(" 先序序列:%s\n",pre);
    printf(" 中序序列:%s\n",in);
    printf(" 构造一颗二叉树b:\n");
    printf(" 括号表示法:");prin(b);printf("\n");
    printf(" 中序序列:%s\n",pre);
    printf(" 后序序列:%s\n",in);
    printf(" 构造一颗二叉树b:\n");
    printf(" 凹入表示法:\n");prin1(b);printf("\n");
}
