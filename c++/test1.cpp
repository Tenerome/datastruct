//接收以1结尾的二进制串
#include"iostream"
using namespace std;
char arr[10];
void Q(int i){
    char q=arr[i];
    i++;
    if(q=='0'){
        if(arr[i]=='\0'){
            cout<<"不接收"<<endl;
        }else{
            Q(i);
        }
    }else if(q=='1'){
        if(arr[i]=='\0'){
            cout<<"接收"<<endl;
        }else{
            Q(i);
        }
    }
}

int main(){
    int i=0;
    cin>>arr;
    Q(i);
}