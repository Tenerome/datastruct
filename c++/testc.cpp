#include"iostream"
using namespace std;

class A{
    public:
    int sub(int x){
        return x--;
    }
    void add(int &x){
        x++;
    }
};
class B:public A{
    public:
    float div(int x,int y){
        return x/y;
    }
};
int main(){
    int i=2,j=4;
    B b;
    b.add(i);
    printf("%d",i);
}