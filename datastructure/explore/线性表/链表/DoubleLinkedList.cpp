//双链表
//本程序的初始节点不是头节点，只是初始化后的第一个点
//开始用p.next==NULL&&p.prior==NULL来判断初始节点，然后对其data域操作，
//但是操作后，L的next和prior还是null的，所以增加flag来标志初始节点
#include<iostream>
using namespace std;

class DoubleLinkedList{//==双链表存储结构==
public:
    int data;
    int flag=0;//flag标志节点是否初始节点,默认不是初始节点
    int len;
    DoubleLinkedList * prior;
    DoubleLinkedList * next;
    DoubleLinkedList(){};
    ~DoubleLinkedList(){};
};

typedef DoubleLinkedList * DuLinkList;

void initList(DuLinkList &L){//==初始化==
    L=(DuLinkList)malloc(sizeof(DoubleLinkedList));
    L->prior=NULL;
    L->next=NULL;
    L->flag=1;//初始化
    L->len=0;//len记录链表长度
}

void listInsert_H(DuLinkList &L,int i,int e){//==前插==
    if(L->flag){//如果是初始节点，把第一个数据插在其data域
        L->data=e;
        L->flag=0;//之后标志位置零
        L->len++;//长度+1
        return;
    }
    int j=1;
    int len=L->len;//记录旧长度
    DuLinkList p=L;
    while(p&&(j<i)){//p移动到待插位置
        p=p->next;
        j++;
    }
    if(!p||j>i){
        cout<<"插入范围无效"<<endl;
        return;
    }
    DuLinkList s=(DuLinkList)malloc(sizeof(DoubleLinkedList));
    s->data=e;
    s->prior=p->prior;
    if(p->prior){
        p->prior->next=s;//p的前驱的后继本来是p，现在是前插的s;(这里，
    }                    //若p是初始节点，则其没有前驱和后继节点)
    s->next=p;           //严蔚敏的教材上没有这一步的判断，导致NULL无
    p->prior=s;          //指针程序错误
    if(i==1){//如果，插在第一个元素前面，则更新L，使L始终为开头
        L=s;
    }
    L->len=len+1;//记录新长度
}

void listInsert_R(DuLinkList &L,int i,int e){//==后插==
    if(L->flag){
        L->data=e;
        L->flag=0;
        L->len++;
        return;
    }
    int j=1;
    int len=L->len;//记录旧长度
    DuLinkList p=L;
    while(p&&(j<i)){
        p=p->next;
        j++;
    }
    if(!p||j>i){
        cout<<"插入范围无效"<<endl;
        return;
    }
    DuLinkList s=(DuLinkList)malloc(sizeof(DoubleLinkedList));
    s->data=e;
    s->next=p->next;
    if(p->next){//同前插，若后继为NULL，则跳过，否则更新
        p->next->prior=s;
    }
    s->prior=p;
    p->next=s;
    L->len=len+1;
}

void printList(DuLinkList &L){//==输出==
    if(L->flag){
        cout<<"NULL<->NULL"<<endl;
        cout<<"链表长度为:0"<<endl;
        return;
    }
    DuLinkList p=L;
    cout<<"输出双链表"<<endl;
    cout<<"NULL<->";
    while(p){//因为头节点最初指向NULL，每次插入后，尾节点都指向NULL
        cout<<p->data<<"<->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
    cout<<"链表长度为:"<<L->len<<endl;
}

void deleteElem(DuLinkList &L,int i){//==删除==
    int j=1;
    int len=L->len;//记录旧长度
    DuLinkList p=L;
    while(p&&(j<i)){
        p=p->next;
        j++;
    }
    if(!p||j>i){
        cout<<"删除范围无效"<<endl;
        return;
    }
    if(!(p->prior||p->next)){//分情况：初始节点
        L->flag=1;//初始节点，flag置1
    }else if(!p->prior){//首节点,此时需要更新L
        p->next->prior=NULL;
        L=p->next;
    }else if(!p->next){//尾节点
        p->prior->next=NULL;
    }else{//中间节点
        p->prior->next=p->next;
        p->next->prior=p->prior;
    }
    L->len=len-1;
}
int main(){
    DuLinkList L;
    initList(L);
    listInsert_H(L,1,23);
    listInsert_H(L,1,45);
    listInsert_H(L,2,12);
    deleteElem(L,2);
    deleteElem(L,1);
    deleteElem(L,1);
    printList(L);
}