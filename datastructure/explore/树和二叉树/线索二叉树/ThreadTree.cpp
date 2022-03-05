//线索二叉树
#include<iostream>
using namespace std;

class threadtree{//==存储结构==
    public:
    char data;
    threadtree *lp,*rp;
    int ltag,rtag;
};

typedef threadtree * Threadtree;

void CreateTree(Threadtree &T){//==先序序列建立二叉树==
    char ch;
    cin>>ch;//cin也可以直接输入字符串自动读取单个字符
    if(ch=='#')
        T=nullptr;
    else{
        T=(Threadtree)malloc(sizeof(threadtree));
        T->data=ch;
        T->ltag=0;
        T->rtag=0;
        CreateTree(T->lp);
        CreateTree(T->rp);
    }
}

void inThread(Threadtree &T,Threadtree &pre){//==线索化==
    if(!T)
        return;
    inThread(T->lp,pre);

    if(!T->lp){
        T->ltag=1;
        T->lp=pre;
    }
    if(!pre->rp){
        pre->rtag=1;
        pre->rp=T;
    }

    pre=T;
    inThread(T->rp,pre);
}

void InOrderThread(Threadtree &p,Threadtree &T){//p是头节点，并和T连接起来
    p=(Threadtree)malloc(sizeof(threadtree));//新建头节点
    p->ltag=0;
    p->rtag=1;
    p->rp=p;
    if(!T){
        p->lp=p;
        return; //根节点不存在，则让头节点左孩子指向自身
    }
    Threadtree pre;
    pre=p;
    p->lp=T;//头节点左孩子指向根节点
    inThread(T,pre);
    pre->rp=p;
    pre->rtag=1;
    p->rp=pre;
}

void InOrderTracerse(Threadtree &T){//非递归遍历线索二叉树
    Threadtree p=T->lp;
    while(p!=T){
        while(p->ltag==0)
            p=p->lp;
        while(p->rtag==1&&p->rp!=T){
            p=p->rp;
            cout<<p->data;
        }
        p=p->rp;
    }
}

void inOrder(Threadtree &T){//test--ok，递归遍历二叉树
    if(T){
        cout<<T->data<<" ";
        inOrder(T->lp);
        inOrder(T->rp);
    }
}

int main(){
    Threadtree T,p;
    CreateTree(T);
    // inOrder(T);
    InOrderThread(p,T);
    InOrderTracerse(p);
}