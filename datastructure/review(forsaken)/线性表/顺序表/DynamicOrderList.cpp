//线性表-顺序表-动态顺序表
#include<iostream>
using namespace std;
#define initSize 3//设置初始大小3

typedef struct{//==定义动态顺序表结构==
    int *data;//用指针操作
    int maxSize;
    int length;
}SeqList;

void initList(SeqList &L){//==初始化==
    L.data=(int *)malloc(initSize * sizeof(int));//动态分配内存，并转为int指针
    L.length=0;
    L.maxSize=initSize;
}

void printList(SeqList &L){//==输出顺序表==
    cout<<"输出顺序表:"<<endl;
    for (int i = 0; i < L.length; i++)
    {
        cout<<L.data[i]<<" ";//指针也可以用[i]下标表示距离指针位置i个单位的地址
    }
    cout<<endl;
}

void increaseSize(SeqList &L,int len){//==动态增加长度==
    int *p=L.data;//先将旧空间首地址存下来
    L.data=new int[L.maxSize + len];//申请新的空间
    for (int i = 0; i < L.length; i++)
    {
        L.data[i]=p[i];//将旧空间的元素转移到新空间
    }
    L.maxSize+=len;
    delete p;//new出来的用过后要delete，避免内存泄漏
    return;
}

void listInsert(SeqList &L,int i,int e){//==插入==
    if(i<1||i>L.length+1){
        cout<<"插入范围无效"<<endl;//判断范围
        return;
    }
    if(L.length>=L.maxSize){
       increaseSize(L,5);//判断余量，若不足，则申请5个新空间
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j]=L.data[j-1];//第i个元素后的元素后移
    }
    L.data[i-1]=e;//插入
    L.length++;
    return;
}

void listDelete(SeqList &L,int i,int &e){//==删除==
    if(i<1||i>L.length){
        cout<<"删除范围无效"<<endl;//判断范围
        return;
    }
    e=L.data[i-1];//记录被删除元素值
    for (int j = i; j < L.length; j++)
    {
        L.data[j-1]=L.data[j];//第i个元素前的元素前移
    }
    L.length--;
    return;
}

void locateElem(SeqList &L,int e){//==查找==
    int i;
    for (i = 0; i < L.length; i++)
    {
        if(L.data[i]==e){
            cout<<"元素"<<e<<"是第"<<i+1<<"个"<<endl;
            return;
        }
    }
    cout<<"未查到元素"<<e<<endl;
    return;
}

void getElem(SeqList &L,int i){//==按序查找==
    if(i<1||i>L.length){
        cout<<"查找范围无效"<<endl;
        return;
    }
    cout<<"第"<<i<<"个元素为"<<L.data[i-1]<<endl;
    return;
}
int main(){
    SeqList L;
    initList(L);
    listInsert(L,1,2);
    listInsert(L,2,3);
    listInsert(L,2,5);
    printList(L);
    listInsert(L,1,1);
    printList(L);
    locateElem(L,5);
    getElem(L,2);
}