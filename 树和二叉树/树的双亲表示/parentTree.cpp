#include<iostream>
using namespace std;
#define maxsize 100

class Tnode{
    public:
    char data;
    int parent;
};

class parentTree{
    public:
    Tnode tnode[maxsize];
    int length;
};

parentTree createTree(){
    parentTree P;
    int j;
    char ch;
    cout<<"输入节点个数:";
    cin>>P.length;
    cout<<"输入节点值及其双亲在数组中的位置下标:"<<endl;
    for(int i=0;i<P.length;i++){
        cin>>ch>>j;
        P.tnode[i].data=ch;
        P.tnode[i].parent=j;
    }
    return P;
}

void findParent(parentTree p){
    char a;
    cout<<"输入要查询的节点值:";
    cin>>a;
    for(int i=0;i<p.length;i++){
        if(p.tnode[i].data==a){
            if(i==0){
                cout<<"该节点为根节点"<<endl;
                return;
            }
            cout<<"节点"<<a<<"的父节点为:"<<p.tnode[p.tnode[i].parent].data<<" ";
            cout<<"其下标为:"<<p.tnode[i].parent<<endl;
            return;
        }
    }
    cout<<"无此节点"<<endl;
    return;
}

int main(){
    parentTree p=createTree();
    findParent(p);
}