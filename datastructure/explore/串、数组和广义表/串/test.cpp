#include<iostream>
#include<string>
#include<stack>
using namespace std;

stack<int> stak;

void index(string str,string ttr){

    for(int i=0;i<str.length();i++){
        if(str[i]==ttr[0]&&str.length()-i>=ttr.length()){
            stak.push(i);
        }
    }
}

int main(){
    string S="aaaabbaabbaabbaacbacbac";
    string T="acb";
    index(S,T);
    cout<<stak.size();
}