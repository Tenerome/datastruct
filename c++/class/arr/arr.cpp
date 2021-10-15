#include "iostream"
using namespace std;

int length(int *p)
{ //获取数组长度函数
    int len;
    while (*p)
    {
        p++;
        len++;
    }
    return len;
}

void prin(int *p)
{ //输出数组,这样输出的数组必须要求是又具体长度的
    while (*p)
    {
        cout << *p << " ";
        p++;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int arr1[6] = {1, 2, 3, 4, 5};
    cout << length(arr) << endl;
    prin(arr);
    cout<<endl << length(arr1) << endl;
    prin(arr1);
    
}