//线索二叉树，中序
#include<iostream>
using namespace std;

class threadtree{//==存储结构==
    public:
        char data;
        threadtree * lp,* rp;
        int ltag=0,rtag=0;//标志位默认为0
};

typedef threadtree * Threadtree;

void createTree(Threadtree &T){//==初始化==
    T=(Threadtree)malloc(sizeof(threadtree));
    T->data='A';
    T->lp=(Threadtree)malloc(sizeof(threadtree));
    T->rp=(Threadtree)malloc(sizeof(threadtree));

    T->lp->data='B';
    T->lp->lp=(Threadtree)malloc(sizeof(threadtree));
    T->lp->rp=(Threadtree)malloc(sizeof(threadtree));

    T->rp->data='C';
    T->rp->lp=(Threadtree)malloc(sizeof(threadtree));
    T->rp->rp=(Threadtree)malloc(sizeof(threadtree));

    T->lp->lp->data='D';
    T->lp->lp->lp=(Threadtree)malloc(sizeof(threadtree));
    T->lp->lp->rp=(Threadtree)malloc(sizeof(threadtree));

    T->lp->rp->data='E';
    T->lp->rp->lp=(Threadtree)malloc(sizeof(threadtree));
    T->lp->rp->rp=NULL;

    T->rp->lp->data='F';
    T->rp->lp->lp=NULL;
    T->rp->lp->rp=NULL;

    T->rp->rp->data='G';
    T->rp->rp->lp=NULL;
    T->rp->rp->rp=NULL;

    T->lp->lp->lp->data='H';
    T->lp->lp->lp->lp=NULL;
    T->lp->lp->lp->rp=NULL;

    T->lp->lp->rp->data='I';
    T->lp->lp->rp->lp=NULL;
    T->lp->lp->rp->rp=NULL;

    T->lp->rp->lp->data='J';
    T->lp->rp->lp->lp=NULL;
    T->lp->rp->lp->rp=NULL;
}

void inThread(Threadtree &T,Threadtree &pre){//==建立中序线索二叉树==
    if(T){//按照递归中序遍历的顺序建立线索
        inThread(T->lp,pre);
        if(!T->lp){//当前节点左孩子为空
            T->lp=pre;
            T->ltag=1;
        }
        if(!pre->rp){//前驱节点右孩子为空
            pre->rp=T;//(前驱节点右孩子相当于不用返回到前驱操作，在操作左孩子的同时也操作右孩子)
            pre->rtag=1;
        }
        pre=T;
        inThread(T->rp,pre);
    }
}

void createThread(Threadtree &T){//==建立线索二叉树==
    Threadtree pre=NULL;//头节点的前驱为空
    if(T){
        inThread(T,pre);
        pre->rp=NULL;//最后一个节点，单独处理，尾节点的后继为空
        pre->rtag=1;
    }
}

Threadtree  firstNode(Threadtree &T){//==求中序序列的头节点==
    while(!T->ltag){
        T=T->lp;
    }
    return T;
}

Threadtree nextNode(Threadtree &T){//==求后继节点==
    if(!T->rtag){
        return firstNode(T->rp);//若无线索,则找右子树的最左下节点，就是右孩子非空，则其后继是其右子树的最左下的节点
    }else{
        return T->rp;
    }
}

void inOrder(Threadtree &T){//==遍历线索二叉树==
    Threadtree p=firstNode(T);
    for(;p!=NULL;p=nextNode(p)){
        cout<<p->data<<" ";
    }
}

void inOrder2(Threadtree &T){//==递归遍历二叉树，用作对比==
    cout<<"递归遍历二叉树:";
    if(T!=NULL){
        inOrder2(T->lp);
        cout<<T->data<<" ";
        inOrder2(T->rp);
    }
    cout<<endl;
}
int main(){
    Threadtree T;
    createTree(T);
    inOrder2(T);
    createThread(T);
    inOrder(T);

}