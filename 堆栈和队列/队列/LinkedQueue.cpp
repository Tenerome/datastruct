//链式队列
//链式队列的首节点不存数据，用它的指针来指第一个元素
#include<iostream>
using namespace std;

class LinkedQueue{//==节点的存储结构==
    public:
    int data;
    LinkedQueue *next;
};
typedef LinkedQueue * Queueptr;
class LinkQueue{//==指针存储结构==
    public:
    Queueptr front;
    Queueptr rear;
};

void initQueue(LinkQueue &Q){//==初始化==
    Q.front=Q.rear=(Queueptr)malloc(sizeof(LinkedQueue));
    Q.front->next=NULL;
}

void Enqueue(LinkQueue &Q,int e){//==入队==
    Queueptr p=(Queueptr)malloc(sizeof(LinkedQueue));
    p->data=e;
    p->next=NULL;
    Q.rear->next=p;//插到队尾
    Q.rear=p;//更新队尾
}

void Dequeue(LinkQueue &Q,int &e){
    if(Q.front==Q.rear){
        cout<<"队空"<<endl;
        return;
    }
    Queueptr p=Q.front->next;//主要利用队首节点来出队
    e=p->data;
    Q.front->next=p->next;//更新队首节点，就删除了第一个元素
    if(Q.rear==p)
        Q.rear=Q.front;//当最后一个元素被删，队尾指针重新指向头节点
    delete p;
}

void getHead(LinkQueue Q){
    if(Q.front==Q.rear)
        cout<<"栈空"<<endl;
    else
        cout<<"队头元素为:"<<Q.front->next->data<<endl;
}
void printQueue(LinkQueue Q){//==输出==
    if(Q.front==Q.rear){
        cout<<"队空"<<endl;
        return;
    }
    Queueptr p=Q.front->next;
    while (p){
        cout<<p->data<<endl;
        p=p->next;
    }
    
}
int main(){
    LinkQueue Q;
    initQueue(Q);
    Enqueue(Q,12);
    Enqueue(Q,23);
    Enqueue(Q,357);
    int e;
    Dequeue(Q,e);
    printQueue(Q);
    getHead(Q);
}