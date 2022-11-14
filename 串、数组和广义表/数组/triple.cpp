//三元组存储稀疏矩阵
#include<iostream>
using namespace std;
#define number 20
class triple{
    public:
    int i,j;//行标i，列标j
    int data;//元素值
};

class TSMatrix{
    public:
    triple data[20];
    int n,m,num;//n:行数;m:列数;num:非零元素个数;
};

void initTsMatrix(TSMatrix &T){
    T.m=3;
    T.n=3;
    T.num=3;//三行三列三个非零元素的稀疏矩阵

    T.data[0].i=1;
    T.data[0].j=1;
    T.data[0].data=1;

    T.data[1].i=2;
    T.data[1].j=3;
    T.data[1].data=5;

    T.data[2].i=3;
    T.data[2].j=1;
    T.data[2].data=3;
}

void display(TSMatrix T){
    for(int i=1;i<=T.n;i++){//非零元素的位置是从1开始的
        for(int j=1;j<=T.m;j++){
            int value=0;
            for(int k=0;k<T.num;k++){
                if(i==T.data[k].i && j==T.data[k].j){
                    cout<<T.data[k].data<<" ";
                    value=1;
                    break;
                }  
            }
            if(value==0){
                cout<<"0"<<" ";
            }
            
            
        }
        cout<<endl;
    }
}

int main(){
    TSMatrix T;
    initTsMatrix(T);
    display(T);
}