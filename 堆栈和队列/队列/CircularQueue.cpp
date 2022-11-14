//循环队列
/*队列的存储本质还是数组，用base指针存储其首地址，用front,rear计数器来做队
首和队尾指示*/
//通过front=(fornt+1)%maxsize来实现循环
#include<iostream>
using namespace std;
#define maxSize 10
class CircularQueue{//==循环队列存储结构==
    public:
    int *base;//存储空间基址
    int front;//头指针
    int rear;//尾指针
};

void initQueue(CircularQueue &Q){//==初始化==
    Q.base=new int[maxSize];
    if(!Q.base){
        cout<<"空间分配失败"<<endl;
        return;
    }
    Q.front=Q.rear=0;
}

void getLength(CircularQueue &Q){//==求长度==
    cout<<"队列长度为:"<<(Q.rear-Q.front+maxSize)%maxSize<<endl;
}

void Enqueue(CircularQueue &Q,int e){//==入队==
    if((Q.rear+1)%maxSize==Q.front){
        cout<<"队满"<<endl;
        return;
    }
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%maxSize;
}

void Dequeue(CircularQueue &Q,int &e){//==出队==
    if(Q.front==Q.rear){
        cout<<"队空"<<endl;
        return;
    }
    e=Q.base[Q.front];
    Q.front=(Q.front+1)%maxSize;
}

void getHead(CircularQueue Q){//==取队头元素==
    if(Q.front==Q.rear)
        cout<<"队空"<<endl;
    else
        cout<<"队头元素为"<<Q.base[Q.front]<<endl;
}

void printQueue(CircularQueue Q){//==输出队列==
    if(Q.front==Q.rear){
        cout<<"队空"<<endl;
        return;
    }
    int p=Q.front;
    while (p<Q.rear){
        cout<<Q.base[p]<<endl;
        p++;
    }
}
int main(){
    CircularQueue Q;
    initQueue(Q);
    Enqueue(Q,12);
    Enqueue(Q,32);
    Enqueue(Q,78);
    int e;
    printQueue(Q);
    Dequeue(Q,e);
    getLength(Q);
    printQueue(Q);
    getHead(Q);
}