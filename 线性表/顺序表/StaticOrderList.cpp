//静态顺序表
#include<iostream>
using namespace std;
#define maxSize 5//定义最大长度
class StaticOrderList//==静态顺序表存储结构==
{
public:
    int * elem;//首地址
    int length;//已存入的元素的长度
    StaticOrderList();
    ~StaticOrderList();
};
StaticOrderList::StaticOrderList()
{
}
StaticOrderList::~StaticOrderList()
{
}

bool initList(StaticOrderList &L){//==初始化==
    L.elem=new int[maxSize];//静态分配空间
    if(!L.elem){
        cout<<"存储空间分配失败"<<endl;
        return false;
    }
    L.length=0;
    return true;
}

bool getElem(StaticOrderList &L,int i,int &e){//==取值==
    if(i<1||i>L.length){
        cout<<"取值范围无效"<<endl;
        return false;
    }
    e=L.elem[i-1];
    return true;
}

int locateElem(StaticOrderList &L,int e){//==查找==
    for (int i = 0; i < L.length; i++)
    {
        if(L.elem[i]==e){
            return i+1;
        }
    }
    cout<<"未查到该元素"<<endl;
    return 0;
}

bool listInsert(StaticOrderList &L,int i,int e){//==插入==
    if(i<1||i>L.length+1){
        cout<<"插入范围无效"<<endl;
        return false;
    }
    if(L.length==maxSize){
        cout<<"空间已满"<<endl;
        return false;
    }
    for(int j=L.length-1;j>=i-1;j--){
        L.elem[j+1]=L.elem[j];
    }
    L.elem[i-1]=e;
    L.length++;
    return true;
}

bool listDelete(StaticOrderList &L,int i){//==删除==
    if(i<1||i>L.length){
        cout<<"删除范围无效"<<endl;
        return false;
    }
    for(int j=i;j<=L.length-1;j++){
        L.elem[j-1]=L.elem[j];
    }
    L.length--;
    return true;
}

void printList(StaticOrderList &L){
    cout<<"输出表:";
    for(int i=0;i<=L.length-1;i++){
        cout<<L.elem[i]<<" ";
    }
    cout<<endl;
}
int main(){
    StaticOrderList L;
    initList(L);
    listInsert(L,1,2);
    listInsert(L,1,4);
    listInsert(L,1,6);
    listInsert(L,1,3);
    listInsert(L,2,7);
    printList(L);
    listDelete(L,2);
    printList(L);
    cout<<L.length;
}