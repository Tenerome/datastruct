//二叉树的先序遍历，中序遍历，后序遍历 递归算法
//先序遍历的非递归算法（中序，后序类似）,栈的思想
//层次遍历,使用队列实现

#include<iostream>
#include<stack>
using namespace std;

int front=0,rear=0;//队列首尾指针

class bitree{//==树存储结构==
    public:
        int data;//数据域
        bitree * lp;//左孩子指针
        bitree * rp;//右孩子指针
};

typedef bitree * Bitree;

void createTree(Bitree &B){//==初始化树==
    B=(Bitree)malloc(sizeof(bitree));
    B->data=1;
    B->lp=(Bitree)malloc(sizeof(bitree));
    B->rp=(Bitree)malloc(sizeof(bitree));

    B->lp->data=2;
    B->lp->lp=(Bitree)malloc(sizeof(bitree));
    B->lp->rp=(Bitree)malloc(sizeof(bitree));

    B->rp->data=3;
    B->rp->lp=(Bitree)malloc(sizeof(bitree));
    B->rp->rp=(Bitree)malloc(sizeof(bitree));

    B->lp->lp->data=4;
    B->lp->lp->lp=NULL;
    B->lp->lp->rp=NULL;

    B->lp->rp->data=5;
    B->lp->rp->lp=NULL;
    B->lp->rp->rp=NULL;

    B->rp->lp->data=6;
    B->rp->lp->lp=NULL;
    B->rp->lp->rp=NULL;

    B->rp->rp->data=7;
    B->rp->rp->lp=NULL;
    B->rp->rp->rp=NULL;
}

void PreOrder(Bitree B){//先序遍历1
    if(B){
        cout<<B->data<<" ";
        PreOrder(B->lp);
        PreOrder(B->rp);
    }
}

void PreOrderTraverse(Bitree B){//先序遍历2
    cout<<"先序遍历:";
    PreOrder(B);
    cout<<endl;
}

void MidOrder(Bitree B){//中序遍历1
    if(B){
        MidOrder(B->lp);
        cout<<B->data<<" ";
        MidOrder(B->rp);
    }
}

void MidOrderTraverse(Bitree B){//中序遍历2
    cout<<"中序遍历:";
    MidOrder(B);
    cout<<endl;
}

void AfOrder(Bitree B){//后序遍历1
    if(B){
        AfOrder(B->lp);
        AfOrder(B->rp);
        cout<<B->data<<" ";
    }
}

void AfOrderTraverse(Bitree B){//后序遍历2
    cout<<"后序遍历:";
    AfOrder(B);
    cout<<endl;
}

void PreOrderTraverse1(Bitree B){//非递归实现先序遍历
    cout<<"先序遍历非递归:";
    stack<Bitree> S;
    Bitree p;
    S.push(B);
    while(!S.empty()){
        p=S.top();
        S.pop();
        while(p){
            cout<<p->data<<" ";
            if(p->rp){
                S.push(p->rp);
            }
            p=p->lp;//核心，中间节点可以是上级的孩子，还可以是下级的根
                    //p一直指向左孩子，当上级遍历完，左孩子就成了下级的根
        }
    }
    cout<<endl;
}

void Enqueue(Bitree *arr,Bitree B){//入队
    arr[rear++]=B;
}

Bitree Dequeue(Bitree* arr){//出队函数
    return arr[front++];
}
void GradationTraverse(Bitree B){//层次遍历
    cout<<"层次遍历:";
    Bitree  p;
    Bitree arr[20];
    Enqueue(arr,B);
    while(front<rear){
        p=Dequeue(arr);
        cout<<p->data<<" ";
        if(p->lp!=NULL){
            Enqueue(arr,p->lp);
        }
        if(p->rp!=NULL){
            Enqueue(arr,p->rp);
        }
    }
    cout<<endl;
}

int main(){
    Bitree B;
    createTree(B);
    PreOrderTraverse(B);
    MidOrderTraverse(B);
    AfOrderTraverse(B);
    PreOrderTraverse1(B);
    GradationTraverse(B);
}