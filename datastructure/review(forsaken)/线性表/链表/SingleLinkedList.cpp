//线性表-链表-单链表
#include<iostream>
using namespace std;

typedef struct LNode{//==定义单链表结构==
    int data;
    struct LNode *next;//指向后继节点的指针
}LNode,*LinkList; /*struct LNode 类型的指针的别名
                 struct LNode *=LinkList
                 LinkList L等价于struct LNode *L;*/

//L->data:L指针所指的结构体的data域
//L->next:L指针所指的结构体的next域

void initList(LinkList &L){//==初始化==
    L=(LinkList)malloc(sizeof(LNode));//分配头节点
    //L=(LNode *)malloc(sizeof(LNode));
    if(L==NULL){
        cout<<"空间已满"<<endl;//指针判空，避免程序异常（空间已满指真实存储已满）
        return;
    }
    L->next=NULL;
    return;
}

void empty(){//单链表判空，即判断

}
int main(){
    LNode l;
    LinkList ha=&l;
    l.data=9;
    cout<<ha->data;

}