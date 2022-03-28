#include"iostream"
using namespace std;

void Q(int q);
void Q1(int q1);
enum {low,high};

void scan(int &q){
    cout<<"输入下一个状态:";
    cin>>q;
}
void Q(int q){
    scan(q);
    switch(q){
        case low:
            Q(q);
            break;
        case high:
            Q1(q);
            break;
        default:
            cout<<"错误"<<endl;
    }
}
void Q1(int q1){
    scan(q1);
    switch(q1){
        case low:
            Q(q1);
            break;
        case high:
            cout<<"接收"<<endl;
            break;
        default:
            cout<<"不接收"<<endl;
    }
}
int main(){
    char q;
    Q(q);
}