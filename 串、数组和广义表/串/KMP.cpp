//串的模式匹配
//KMP算法
#include<iostream>
#include<string>
using namespace std;

void getNext(string T,int next[]){//求next数组
    int i=1,j=0;
    next[1]=0;
    while(i<T.length()){
        if(j==0||T[i-1]==T[j-1]){//下标从0开始
            i++;
            j++;
            next[i]=j;
        }else{
            j=next[j];
        }
    }
}
void Index_KMP(string S,string T,int next[]){
    int i=1,j=1;
    while(i<=S.length()&&j<=T.length()){
        if(j==0||S[i-1]==T[j-1]){
            i++;
            j++;
        }else{
            j=next[j];
        }
    }
    if(j>T.length()){
            cout<<"匹配成功"<<endl;
            cout<<"T在S中的起始位置是:"<<i-T.length()<<endl;
        }else{
            cout<<"匹配失败"<<endl;
        }
}

int main(){
    string str="aaaabcd";
    string ttr="aabc";
    int next[100];
    getNext(ttr,next);
    Index_KMP(str,ttr,next);
}