//文件的输入输出
#include <iostream>
#include <fstream>
using namespace std; //ifstream,ofstream都是std中的
int main()
{
    char c;
    ifstream fin;  //获取打开的文件的内容，待写入变量，只能和>>匹配
    ofstream fout; //打开一个文件，将内容写入这个文件,只能和<<匹配
    fstream file;  //打开一个文件，用>>是读文件内容，用<<是写文件内容

    char aa[100], bb[100] = "HHALL", cc[100];

    fin.open("aa.txt");
    fout.open("bb.txt");
    file.open("cc.txt");

    fin >> aa;  //将aa.txt的内容写到aa   相当与aa.txt>>fin>>aa    从文件读
    fout << bb; //相当于bb.txt<<fout<<bb,将bb的内容写到bb.txt,也可以是直接的字符串      向文件写
    file >> cc;
    file << bb;
    //fout <<"Hello,world"<<endl;//将"Hello,world"写入bb.text
    fin.close();
    fout.close();
    cout << aa[1] << endl;
    cout << cc[0] << endl;
}