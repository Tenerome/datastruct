#include <iostream>
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
    int arr[100] = {3, 6, 9, 13, 34, 56, 78}, x, i = 0, len, j;
    int *p = arr;
    len = length(arr);
    cout<<"primary array:";
    prin(arr);
    cout<<endl<<"input:";
    cin >> x;
    while (*(p + i) < x)
        i++;
    for (j = 6; j >=i; j--)
    {
        *(p + j + 1) = *(p + j);
    }
    *(p + i) = x;
    cout<<"modificated array:";
    prin(arr);
}