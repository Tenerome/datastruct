#include"6.h"
#include"iostream"
using namespace std;
int main(){
    Personnel p1;
    p1.input();
    p1.prin();
    Personnel p2(p1);
    p2.input(9,"陈建安","男");
    p2.prin();
}