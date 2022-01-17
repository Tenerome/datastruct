//动态顺序表
#include<iostream>
using namespace std;
#define initSize 3
class DynamicOrderList
{
public:
    int *elem;
    int length;
    int maxSize;
    DynamicOrderList(){};
    ~DynamicOrderList(){};
};

bool initList(DynamicOrderList &L){//==初始化==
    L.elem=(int *)malloc(initSize * sizeof(int));
    if(!L.elem){
        cout<<"存储空间分配失败"<<endl;
        return false;
    }
    L.length=0;
    L.maxSize=initSize;
    return true;
}

void increaseSize(DynamicOrderList &L,int len){//动态增加长度
    int *p=L.elem;
    L.elem=new int[L.maxSize + len];
    for(int i=0;i<L.length;i++){
        L.elem[i]=p[i];
    }
    L.maxSize+=len;
    delete p;
}

bool getElem(DynamicOrderList &L,int i,int &e){//==取值==
    if(i<1||i>L.length){
        cout<<"取值范围无效"<<endl;
        return false;
    }
    e=L.elem[i-1];
    return true;
}

int locateElem(DynamicOrderList &L,int e){//==查找==
    for (int i = 0; i < L.length; i++)
    {
        if(L.elem[i]==e){
            return i+1;
        }
    }
    cout<<"未查到该元素"<<endl;
    return 0;
}

bool listInsert(DynamicOrderList &L,int i,int e){//==插入==
    if(i<1||i>L.length+1){
        cout<<"插入范围无效"<<endl;
        return false;
    }
    if(L.length==L.maxSize){
        increaseSize(L,2);//空间满了之后再申请
    }
    for(int j=L.length-1;j>=i-1;j--){
        L.elem[j+1]=L.elem[j];
    }
    L.elem[i-1]=e;
    L.length++;
    return true;
}

bool listDelete(DynamicOrderList &L,int i){//==删除==
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

void printList(DynamicOrderList &L){
    cout<<"输出表:";
    for(int i=0;i<=L.length-1;i++){
        cout<<L.elem[i]<<" ";
    }
    cout<<endl;
}
int main(){
    DynamicOrderList L;
    initList(L);
    listInsert(L,1,2);
    listInsert(L,1,3);
    listInsert(L,2,7);
    printList(L);
    cout<<L.maxSize;
    listInsert(L,2,5);
    printList(L);
    cout<<L.maxSize;
}