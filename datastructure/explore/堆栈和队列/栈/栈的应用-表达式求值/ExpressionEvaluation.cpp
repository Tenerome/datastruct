//表达式求值
#include<iostream>
#include<stack>
using namespace std;

stack<char> Schar;//运算符栈
stack<double> Sdouble;//操作数栈

int getIndex(char operat){//==获取运算符对应的索引==
    int index=-1;
    switch(operat){
        case '+':
            index=0;
            break;
        case '-':
            index=1;
            break;
        case '*':
            index=2;
            break;
        case '/':
            index=3;
            break;
        case '(':
            index=4;
            break;
        case ')':
            index=5;
            break;
        case '#':
            index=6;
            break;
        default:
            cout<<"error:非法符号";
            break;
    }
    return index;
}

char getPriority(char operat1,char operat2){
    const char priority[][7]={
        {'>', '>', '<', '<', '<', '>', '>'},
        {'>', '>', '<', '<', '<', '>', '>'},
        {'>', '>', '>', '>', '<', '>', '>'},
        {'>', '>', '>', '>', '<', '>', '>'},
        {'<', '<', '<', '<', '<', '=', '0'},
        {'>', '>', '>', '>', '0', '>', '>'},
        {'<', '<', '<', '<', '<', '0', '='},
    };
    int index1=getIndex(operat1);
    int index2=getIndex(operat2);
    return priority[index1][index2];//这里没有异常处理,当index=-1
}

double calculate(double a,char operat,double b){//==计算a operat b==
    switch(operat){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
        default:
            cout<<"error:非法符号";
            return -1;
    }
}

double getAnswer(){//==求表达式值==
    Schar.push('#');
    int counter=0;
    char c=getchar();
    while(c!='#'||Schar.top()!='#'){//当读完c，两个字符都是#时退出循环，计算完毕
        if(isdigit(c)){//isdiget()判断c是字符还是数字
            if(counter==1){//如果counter为1，表示多位数
                double t=Sdouble.top();//取一位数
                Sdouble.pop();//一位数出栈
                Sdouble.push(t*10+(c-'0'));//入栈多位数
                counter=1;//再置一
            }else{
                Sdouble.push(c-'0');//将一位数入栈
                counter++;
            }
            c=getchar();
        }else{
            counter=0;//counter置零
            switch(getPriority(Schar.top(),c)){
                case '<'://优先级不符合，符号入栈
                    Schar.push(c);
                    c=getchar();
                    break;
                case '='://如果两个符号分别时'('和')'则弹出),先计算括号里优先级低的算式
                    Schar.pop();
                    c=getchar();
                    break;
                case '>'://优先级符合时运算
                    char operat=Schar.top();
                    Schar.pop();//取运算符
                    double a=Sdouble.top();
                    Sdouble.pop();//取操作数1
                    double b=Sdouble.top();
                    Sdouble.pop();//取操作数2
                    Sdouble.push(calculate(b,operat,a));//计算，并入栈
            }
        }
    }
    return Sdouble.top();
}

int main(){
    cout<<"输入表达式(以#结尾)"<<endl;
    while(!Schar.empty())
        Schar.pop();
    while(!Sdouble.empty())//若两个栈初始非空,则将其所有元素出栈
        Sdouble.pop();
    double ans=getAnswer();
    cout<<ans<<endl;
    cout<<ans<<endl;
}

