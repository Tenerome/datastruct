#include "stdio.h"
#include "stdbool.h"
#define N 4
#define size 100

typedef int ElemType;
typedef struct
{
    int r;//行号
    int c;//列号
    ElemType d;//元素值
}Tnode;//三元组
typedef struct
{
    int rows;//行数
    int cols;//列数
    int nums;//非零元素数量
    Tnode data[size];

}Tsnode;//三元顺序组

void scan(Tsnode &t,ElemType a[N][N])//录入
{
    int i,j;
    t.rows=N;
    t.cols=N;
    t.nums=0;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            if(a[i][j]!=0)
                {
                    t.data[t.nums].r=i;//行号
                    t.data[t.nums].c=j;//列号
                    t.data[t.nums].d=a[i][j];//元素值
                    t.nums++;//非零元素个数加1
                }

}
void prin(Tsnode t)//输出
{
    int i;
    for(i=0;i<t.nums;i++)
         printf("\t%d\t%d\t%d\n", t.data[i].r, t.data[i].c, t.data[i].d);



}
void tran(Tsnode t,Tsnode &u)//转置
{
    int i,j;
    int k = 0; // k为u.data的下标
    u.rows = t.cols; // 转置矩阵行数值
    u.cols = t.rows; // 转置矩阵列数值
    u.nums = t.nums; // 转置矩阵非零元素个数
    if(t.nums != 0)
        {
            for(j = 0; j < t.cols; j++) // u.data[k]中的记录以c域的次序排列
        {
    for(i = 0; i < t.nums; i++) // i为t.data的下标
        {
            if(t.data[i].c == j)
                {
                    u.data[k].r = t.data[i].c; // 转置矩阵的行号
                    u.data[k].c = t.data[i].r; // 转置矩阵的列号
                    u.data[k].d = t.data[i].d; // 转置矩阵的元素值
                    k++;
                }
        }
        }
        }
}
void sum(Tsnode a,Tsnode b,Tsnode &c)//求和
{
    int i = 0; // a中非零元素个数索引
    int j = 0; // b中非零元素个数索引
    int k = 0; // c中非零元素个数
    ElemType v;
    c.rows = a.rows;
    c.cols = a.cols;
    while(i < a.nums && j < b.nums) // 处理a和b中的元素(假设 a.nums = 6, b.nums = 4)
    {
        if(a.data[i].r == b.data[j].r) // a元素的行号等于b元素的行号
        {
            if(a.data[i].c < b.data[j].c) // a元素的列号小于b元素的列号
            {
                // 将a元素添加到c中
                c.data[k].r = a.data[i].r;
                c.data[k].c = a.data[i].c;
                c.data[k].d = a.data[i].d;
                k++;
                i++;
            }
            else if(a.data[i].c > b.data[j].c) // a元素的列号大于b元素的列号
            {
                // 将b元素添加到c中
                c.data[k].r = b.data[j].r;
                c.data[k].c = b.data[j].c;
                c.data[k].d = b.data[j].d;
                k++;
                j++;
            }
            else // a元素的列号等于b元素的列号
            {
                v = a.data[i].d + b.data[j].d;
                if(v != 0) // 只将不为0的结果添加到c中
                {
                    c.data[k].r = a.data[i].r;
                    c.data[k].c = a.data[i].c;
                    c.data[k].d = v;
                    k++;
                }
                i++;
                j++;
            }
        }
        else if(a.data[i].r < b.data[j].r) // a元素的行号小于b元素的行号
        {
            // 将a元素添加到c中
            c.data[k].r = a.data[i].r;
            c.data[k].c = a.data[i].c;
            c.data[k].d = a.data[i].d;
            k++;
            i++;
        }
        else // a元素的行号大于b元素的行号
        {
            // 将b元素添加到c中
            c.data[k].r = b.data[j].r;
            c.data[k].c = b.data[j].c;
            c.data[k].d = b.data[j].d;
            k++;
            j++;
        }
        c.nums = k;
    }



}
int getij(Tsnode t,int i,int j)//返回三元组t表示的a[i][j]
{
     int k = 0;

    while(k < t.nums && (t.data[k].r != i || t.data[k].c != j))
        k++;
    if(k < t.nums)
        return t.data[k].d;
    else
        return 0;


}
void mul(Tsnode a,Tsnode b,Tsnode &c)//求积
{
    {
    int i;
    int j;
    int k;
    int p = 0; // 矩阵c的非零元素个数
    ElemType s;
    for(i = 0; i < a.rows; i++) // 矩阵c的行数
    {
        for(j = 0; j < b.cols; j++) // 矩阵c的列数
        {
            s = 0;
            for(k = 0; k < a.cols; k++)
            {
                 s = s + getij(a, i, k) * getij(b, k, j); // 求三元组元素
            }
            if(s != 0) // 产生一个三元组元素
            {
                c.data[p].r = i; // 三元组元素的行号
                c.data[p].c = j; // 三元组元素的列号
                c.data[p].d = s; // 三元组元素的元素值
                p++;
            }
        }
    }

    c.rows = a.rows;
    c.cols = b.cols;
    c.nums = p; // 矩阵c的非零元素个数

}

}


int main()
{
    ElemType a1[N][N]={
        {1,0,3,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,1,1}
    };
    ElemType b1[N][N]={
        {3,0,0,0},
        {0,4,0,0},
        {0,0,1,0},
        {0,0,0,2}
    };
    Tsnode a,b,c;
    scan(a,a1);
    scan(b,b1);
    printf("a:\n");
    prin(a);
    printf("b:\n");
    prin(b);
    printf("azhuanzhi:\n");
    tran(a,c);
    prin(c);
    printf("a+b:\n");
    sum(a,b,c);
    prin(c);
    printf("a*b:\n");
    mul(a,b,c);
    prin(c);




}
