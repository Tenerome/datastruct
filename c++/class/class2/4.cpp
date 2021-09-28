//todo  怎么输入输出不确定长度的数组，指针
// ？ 对于a[6]，len=7，a[100],len=6
#include<iostream>
#define  Max 1000;
using namespace std;

void prin(int *p){//输出
   while (*p)
   {
      cout<<*p<<" ";
      p++;
   }
   cout<<endl;
   
}
void chg(int *p){
    int i=0,j;//查找并改变所有重复值
    while(*(p+i)){
    j=i+1;
    while(*(p+j)){
        if(*(p+i)==*(p+j))
        *(p+j)=Max;
        j++;
    }
   i++;
    }
}
void del(int *p){//删除,本质是不输出Max
    while(*p){
        if(*p!=1000)
            cout<<*p<<" ";
        p++;
    }
}
int main(){
    int a[100]={2,2,2,3,4,4,5,6,6,6,6,7,7,8,9,9,10,10,10};
    cout<<"primary array:"<<endl;
    prin(a);
    chg(a);
    cout<<"changed:"<<endl;
    del(a);
    
}