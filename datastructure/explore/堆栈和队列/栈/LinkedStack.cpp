//链式栈
#include<iostream>
using namespace std;

class LinkedStack{//==链式栈存储结构==
public:
    int data;
    LinkedStack *next;
    LinkedStack(){};
    ~LinkedStack(){};
};
typedef LinkedStack * Linkpoint;

void initStack(Linkpoint &S){//==初始化==
    S=NULL;
}

void Push(Linkpoint &S,int e){//==入栈==
    Linkpoint p=(Linkpoint)malloc(sizeof(LinkedStack));
    p->data=e;
    p->next=S;
    S=p;
}

void Pop(Linkpoint &S,int &e){
    if(S==NULL){
        cout<<"栈空"<<endl;
        return;
    }
    e=S->data;
    Linkpoint p=S;//用p临时保存栈顶元素空间
    S=S->next;
    delete p;//修改完后释放空间，提高空间利用率
}

void getElem(Linkpoint &S){
    if(S==NULL){
        cout<<"栈空"<<endl;
        return;
    }
    cout<<"栈顶元素为:"<<S->data<<endl;
}

void printStack(Linkpoint &S){
    Linkpoint p=S;
    while (p){
        cout<<p->data<<endl;
        p=p->next;
    }
    delete p;
}

int main(){
    Linkpoint S;
    initStack(S);
    Push(S,12);
    Push(S,43);
    Push(S,123);
    printStack(S);
}