#include"iostream"
using namespace std;

class point{
    public:
    int x=1;
    point(){
        cout<<"构造"<<endl;
    };
    ~point(){
        cout<<"析构"<<endl;
    };
    int fuc(int x){return x+1999;};
};
void funn(){
    cout<<"funn";
}

int main(){
    point x;
    x->fuc(1);
}