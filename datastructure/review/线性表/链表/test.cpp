#include<iostream>
using namespace std;
class test
{   
public:
    int data;
    test* next;
    test();
    ~test();
};

test::test()
{
}

test::~test()
{
}

void init(test &t){
    t.data=0;
    t.next=NULL;
}
void insert(test &t,int e){
    test t1;
    t1.data=e;
    t1.next=t.next;
    t.next=&t1;
}
int main(){
    test T;
    init(T);
    insert(T,2);
    insert(T,3);
    cout<<T.data;
}