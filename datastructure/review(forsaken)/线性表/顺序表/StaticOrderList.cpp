//线性表-顺序表-静态顺序表
//顺序表的操作顺序是从1开始的，而对顺序表下标访问是从零开始的
#include<iostream>
using namespace std;
#define maxSize 10

typedef struct//==定义静态顺序表的结构==
{
    int data[maxSize];
    int length;
}SqList;

void initList(SqList &L){//==初始化顺序表==
    for (int i = 0; i < maxSize; i++)
    {
        L.data[i]=0;//将所有元素置零
    }
    L.length=0;//顺序表长度置零
}

void printList(SqList &L){//==输出==
    cout<<"输出元素:"<<endl;
    for (int i = 0; i < L.length; i++)
    {
        cout<<L.data[i]<<" ";
    }
    cout<<endl;
}

void listInsert(SqList &L,int i,int e){//==插入,i:待出入位置，e待插入元素==
    if(i<1||i>L.length+1){
        cout<<"插入位置无效"<<endl;//判断位置有效性
        return;//void类型时，直接return退出函数
    }
    if(L.length>=maxSize){
        cout<<"存储空间已满"<<endl;//判断空间余量
        return;
    }
    for (int j = L.length; j>=i; j--)//将第i个元素之后的元素后移
    {
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
}

void listDelete(SqList &L,int i,int &e){//==删除第i个元素，并记录其值==
    if(i<1||i>L.length){
        cout<<"删除位置无效"<<endl;//判断位置
        return;
    }
    e=L.data[i-1];//记录被删除元素的值
    for (int j = i; j < L.length; j++)
    {
        L.data[j-1]=L.data[j];//i元素后所有元素前移
    }
    L.length--;
    
}

void locateElem(SqList &L,int e){//==按值查找==
    int i=0;
    for ( i = 0; i < L.length; i++)
    {
        if(L.data[i]==e){
            cout<<"元素"<<e<<"在第"<<i+1<<"位"<<endl;
            return;
        }
           
    }
    cout<<"未查到该元素"<<endl;
    
}

void getElem(SqList L,int i){//==按序查找==
    if(i<1||i>L.length){
        cout<<"查找范围无效"<<endl;
        return;
    }
    cout<<"第"<<i<<"个元素为"<<L.data[i-1]<<endl;
}
int main(){//==test==
    SqList L;
    initList(L);
    listInsert(L,1,2);
    listInsert(L,2,5);
    listInsert(L,3,9);
    listInsert(L,2,4);
    printList(L);
    locateElem(L,9);
    getElem(L,5);
}

