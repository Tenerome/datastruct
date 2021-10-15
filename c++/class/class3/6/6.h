#ifndef C6_H
#define C6_H
#include"iostream"
using namespace std;
class Personnel{
    int num;
    std::string name;
    std::string sex;

    public:
    Personnel();//构造函数
    Personnel(const Personnel &another);//复制构造函数
    void prin();//成员函数
    void input(int num=0,string name="张三",string sex="男");//带默认形参的成员函数
};
#endif