//串的顺序存储
//BF算法实现串的模式匹配
//直接使用c++库函数string
#include<iostream>
#include<string>
using namespace std;

void Index_BF(string S,string T){//S主串，T子串
    int i=0,j=0;
    while(i<=S.length()-1&&j<=T.length()-1){
        if(S[i]==T[j]){
            i++;
            j++;
        }else{
            i=i-j+1;//一旦查找不对，i从下一位，j从首位开始重新比较
            j=0;
        }
    }
    if(j>T.length()-1){//退出循环时，如果j达到条件，则匹配到了，i达到条件，则匹配失败
        cout<<"匹配成功"<<endl;
        cout<<"子串在主串的位置是:"<<i-T.length()+1<<endl;
    }else{
        cout<<"匹配失败"<<endl;
    }
}
int main(){
    string str="hei,Can I help you?";
    string ttr="help";
    Index_BF(str,ttr);
}