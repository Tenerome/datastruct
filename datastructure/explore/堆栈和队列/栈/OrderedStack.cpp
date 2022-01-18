//顺序栈
//初始化后，base始终指向栈底，若base==NULL，表明栈结构不存在。top初始
//指向栈底，表明空栈，每当有元素入栈时top++，出栈时top--
#include<iostream>
using namespace std;
#define maxsize 3

class OrderedStack{//==顺序栈存储结构==
public:
    int *base;//栈底
    int *top;//栈顶
    int stacksize;//栈可用容量
    OrderedStack(){};
    ~OrderedStack(){};
};

void initStack(OrderedStack &S){
    S.base=new int[maxsize];
    if(!S.base){
        cout<<"存储空间分配失败"<<endl;
        return;
    }
    S.top=S.base;//top初始化为base，空栈
    S.stacksize=maxsize;
}

void Push(OrderedStack &S,int e){//==入栈==
    if(S.top-S.base==S.stacksize){
        cout<<"栈空间已满"<<endl;
        return;
    }
    *S.top=e;
    S.top++;
}

void Pop(OrderedStack &S,int &e){//==出栈==
    if(S.top==S.base){
        cout<<"栈空"<<endl;
        return;
    }
    S.top--;
    e=*S.top;
}

void getTop(OrderedStack &S){//==获取栈顶元素==
    if(S.top==S.base){
        cout<<"栈空"<<endl;
        return;
    }
    cout<<"栈顶元素为"<<*(S.top-1)<<endl;
}

void isEmpty(OrderedStack &S){//==判空==
    if(S.top==S.base){
        cout<<"栈空"<<endl;
    }else{
        cout<<"栈非空"<<endl;
    }
}

void printStack(OrderedStack &S){//==输出栈==
    int *p=S.top;
    cout<<"输出栈"<<endl;
    while(!(p==S.base)){
        cout<<"|"<<*(p-1)<<"|"<<endl;
        p--;
    }
}

int main(){
  OrderedStack S;
  initStack(S);
  Push(S,12);
  Push(S,13);
  Push(S,9);
  printStack(S);
}