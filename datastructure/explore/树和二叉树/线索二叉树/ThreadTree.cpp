//线索二叉树
#include<iostream>
using namespace std;

typedef enum{Link,Thread} pointTag;
class threadTree{
    public:
    char data;
    threadTree *lp,*rp;
    pointTag ltag,rtag;
};
typedef threadTree * ThreadTree;

void createBithrnode(ThreadTree &T){//先序序列建立二叉树
    char ch;
    cin>>ch;
    if(ch=='#')
        T=nullptr;
    else{
        if(!(T=(ThreadTree)malloc(sizeof(threadTree)))){
            cout<<"空间不足"<<endl;
            return;
        }
        T->data=ch;
        T->ltag=Link;
        T->rtag=Link;
        createBithrnode(T->lp);
        createBithrnode(T->rp);
    }
}

void inThread(ThreadTree &T,ThreadTree &pre){//二叉树线索化
    if(!T)
        return;
    inThread(T->lp,pre);

    if(!T->lp){
        T->ltag=Thread;
        T->lp=pre;
    }

    if(!pre->rp){
        pre->rtag=Thread;
        pre->rp=T;
    }

    pre=T;

    inThread(T->rp,pre);
}

void headThread(ThreadTree &p,ThreadTree &T){//添加头节点
    if(!(p=(ThreadTree)malloc(sizeof(threadTree)))){
        cout<<"空间不足"<<endl;
        return;
    }
    p->ltag=Link;
    p->rtag=Thread;
    p->rp=p;

    if(!T){
        p->lp=p;
        return;
    }

    ThreadTree pre;
    pre=p;
    p->lp=T;
    inThread(T,pre);
    //线索化完成，再处理最后的节点
    pre->rp=p;
    pre->rtag=Thread;
    p->rp=pre;
}

void inThreadtraverse(ThreadTree T){
    ThreadTree p=T->lp;
    cout<<"非递归遍历中序二叉树:";
    while(p!=T){
        while(p->ltag==Link){
            p=p->lp;//走到左子树尽头，就是中序遍历的第一个叶子
        }

        cout<<p->data<<" ";

        while(p->rtag==Thread && p->rp!=T){
            p=p->rp;
            cout<<p->data<<" ";
        }
        p=p->rp;
    }
}

int main(){
    ThreadTree p,T;
    cout<<"先序序列建立二叉树:";
    createBithrnode(p);
    headThread(T,p);
    inThreadtraverse(T);

}