#include <iostream>
using namespace std;

int length(float *p)
{            //获取数组长度函数
    int len; //ok
    while (*p)
    {
        p++;
        len++;
    }
    return len;
}
int main()
{
    float a[100], sum = 0, avg,b;
    char ch;
    int i = 0;
    cout<<"input grades and end with one negative number:"<<endl;
    while (1)
    {
        cin>>b;
        if(b<0)
            break;
        else
            a[i++]=b;
       
    }

    int len = length(a);
    for (i = 0; i < len; i++)
    { //for循环里不能用函数？
        sum += a[i];
    }
    avg = sum / len;
    cout << "avg:" << avg << endl
         << "less than avg:";

    for (i = 0; i < len; i++)
    {
        if (a[i] < avg)
            cout << a[i] <<" ";
    }
}