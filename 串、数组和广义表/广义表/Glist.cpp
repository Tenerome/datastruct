//广义表
//存储表{a,{b,c,d}};
#include <iostream>
using namespace std;

class glist{
public:
    int tag;   //标志域
    char atom; //原子节点值域
    glist *hp; //指向表头
    glist *tp; //指向下一个元素
};

typedef glist *Glist;

void createList(Glist &L){
    //节点1
    L = (Glist)malloc(sizeof(glist));
    L->tag = 1;
    L->hp = (Glist)malloc(sizeof(glist));
    L->tp = NULL;
    //节点2
    L->hp->tag = 0;
    L->hp->atom = 'a';
    L->hp->tp = (Glist)malloc(sizeof(glist));
    //节点3
    L->hp->tp->tag = 1;
    L->hp->tp->hp = (Glist)malloc(sizeof(glist));
    L->hp->tp->tp = NULL;
    //节点4
    L->hp->tp->hp->tag = 0;
    L->hp->tp->hp->atom = 'b';
    L->hp->tp->hp->tp = (Glist)malloc(sizeof(glist));
    //节点5
    L->hp->tp->hp->tp->tag = 0;
    L->hp->tp->hp->tp->atom = 'c';
    L->hp->tp->hp->tp->tp = (Glist)malloc(sizeof(glist));
    //节点6
    L->hp->tp->hp->tp->tp->tag = 0;
    L->hp->tp->hp->tp->tp->atom = 'd';
    L->hp->tp->hp->tp->tp->tp = (Glist)malloc(sizeof(glist));
    //结束标志
    L->hp->tp->hp->tp->tp->tp->tag=-1;
}
// tap==1,则L的下级有值，L=L->hp
// tap==0,L的同级有值，L=L->tp
//退出的条件是tag==0&&L->tp==NULL(非空表)
void display(Glist L){
    while(1){
        if (L->tag==1){
            L = L->hp;
            cout<<"{";
        }else if(L->tag==0){
            cout << L->atom;
            L = L->tp;
        }else{
            break;
        }
    }
    cout<<"}";

}

int main(){
    Glist L;
    createList(L);
    display(L);
   
}