#include<iostream>
using namespace std;

#define maxSize 100

class Tchild{//孩子
    public:
    int child;//孩子下标
    Tchild* next;//链表实现
};

class Tnode{//节点值
    public:
    char data;
    Tchild * first;
};

class cTree{//节点数组
    public:
    Tnode tnode[maxSize];
    int length;//节点个数
};

Tchild * TChild(){
    Tchild *p=(Tchild *)malloc(sizeof(Tchild));
    p->next=nullptr;
    return p;
}

cTree createTree(){
    cTree C;
    cout<<"输入节点个数:"<<endl;
    cin>>C.length;
    for(int i=0;i<C.length;i++){
        cout<<"输入第"<<i+1<<"个节点的值:";
        cin>>C.tnode[i].data;
        C.tnode[i].first=TChild();
        cout<<"输入节点"<<C.tnode[i].data<<"的孩子节点的数量:";
        int num;
        cin>>num;
        if(num!=0){
            Tchild *p=C.tnode[i].first;
            for(int j=0;j<num;j++){
                Tchild * pc=TChild();
                cout<<"输出第"<<j+1<<"个孩子在顺序表中的位置:";
                cin>>pc->child;
                p->next=pc;
                p=p->next;
            }
        }
    }
    return C;    
}

void findChild(cTree C){
    system("cls");
    char ch;
    cout<<"输入查找的节点:";
    cin>>ch;
    for(int i=0;i<C.length;i++){
        if(C.tnode[i].data==ch){
            Tchild *p=C.tnode[i].first->next;
            if(!p){
                cout<<"该节点为叶子"<<endl;
                return;
            }
            cout<<"节点"<<ch<<"的孩子节点为:";
            while(p){
                cout<<C.tnode[p->child].data<<" ";
                p=p->next;
            }
        }
    }
}

int main(){
    cTree C=createTree();
    findChild(C);
}