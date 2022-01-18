//有头节点的单链表
/*ps:开始用的对象和指针，后来发现函数中实例化的对象是局部变量，返回出来的L
只能记录相邻的数据，之后的数据随函数释放而消失，所以改用malloc分配空间，对
地址的操作是可以记录的*/

#include<iostream>
using namespace std;
class SingleLinkedList{//==单链表的存储结构==
public:
    int data;
    SingleLinkedList *nextp;
    SingleLinkedList(){};
    ~SingleLinkedList(){};
};
typedef SingleLinkedList * Linkpoint;

void initList(Linkpoint &L){//==初始化==
    L=(Linkpoint)malloc(sizeof(SingleLinkedList));
    L->data=0;//头节点的data域存单链表的长度
    L->nextp=NULL;//nextp域存下一个节点地址
}

void listInsert(Linkpoint &L,int i,int e){//插入
    Linkpoint p=L;//在函数内对L操作都用新的指针，不要直接对L操作
    Linkpoint s=(Linkpoint)malloc(sizeof(SingleLinkedList));
    int j=1;
    while(p&&(j<i)){
        p=p->nextp;
        j++;
    }
    if(!p||j>i){
        cout<<"插入范围无效"<<endl;
        return;
    }
    s->data=e;
    s->nextp=p->nextp;
    p->nextp=s;
    L->data++;
}

void printList(Linkpoint &L){//==输出==
    Linkpoint p=L->nextp;
    cout<<"输出单链表"<<endl;
    while(p){//因为头节点最初指向NULL，每次插入后，尾节点都指向NULL
        cout<<p->data<<"->";
        p=p->nextp;
    }
    cout<<"NULL"<<endl;
    cout<<"单链表的长度为:"<<L->data<<endl;
}

void getElem(Linkpoint &L,int i){//==取值==
    Linkpoint p=L->nextp;
    int j=1;
    while (p&&(j<i)){
        p=p->nextp;
        j++;
    }
    if(!p||j>i){
        cout<<"取值范围无效"<<endl;
        return;
    }
    cout<<"第"<<i<<"个元素为:"<<p->data<<endl;
}

void locateElem(Linkpoint &L,int e){//==查找==
    Linkpoint p=L->nextp;
    int j=1;
    while(p){
        if(p->data==e){
            cout<<"元素"<<e<<"在第"<<j<<"位"<<endl;
            return;
        }
        p=p->nextp;
        j++;
    }
    cout<<"待查找元素不存在"<<endl;
}

void deleteElem(Linkpoint &L,int i){//==删除==
    Linkpoint p=L;
    Linkpoint s=(Linkpoint)malloc(sizeof(SingleLinkedList));
    int j=1;
    while(p&&(j<i)){
        p=p->nextp;
        j++;
    }
    if(!p||j>i){
        cout<<"删除范围无效"<<endl;
        return;
    } 
    Linkpoint q;
    q=p->nextp;
    p->nextp=q->nextp;//令p-next指向p-next-next就把p-next删除了
    delete q;
    L->data--;
}

//建立单链表-头插法和尾插法
void createList_H(Linkpoint &L,int n){//==输入n个字符插入单链表==
    L=(Linkpoint)malloc(sizeof(SingleLinkedList));
    L->nextp=NULL;
    L->data=0;//L.data存长度
    cout<<"输入数据按回车继续:";
    for(int i=0;i<n;i++){
        Linkpoint p=(Linkpoint)malloc(sizeof(SingleLinkedList));
        cin>>p->data;
        p->nextp=L->nextp;
        L->nextp=p;
        L->data++;
    }
}

void createList_R(Linkpoint &L,int n){//==尾插法==
    L=(Linkpoint)malloc(sizeof(SingleLinkedList));
    L->nextp=NULL;
    L->data=0;
    Linkpoint r=L;
    for(int i=0;i<n;i++){
        Linkpoint p=(Linkpoint)malloc(sizeof(SingleLinkedList));
        cin>>p->data;
        p->nextp=NULL;
        r->nextp=p;
        r=p;
        L->data++;
    }
}
int main(){
    Linkpoint L;
    initList(L);
    listInsert(L,1,3);
    listInsert(L,1,2);
    listInsert(L,1,5);
    listInsert(L,1,7);
    listInsert(L,1,1);
    printList(L);
    deleteElem(L,3);
    printList(L);
}