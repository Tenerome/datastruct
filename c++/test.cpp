//自定义的命名空间是没有cout,endl等函数的，这些是std空间的
#include <iostream>
namespace spaceA
{

}
using namespace spaceA;
using std::cout;
using std::endl;
template <typename T>
T max(T a, T b)
{
    if (a < b)
        return a;
    else
        return b;
}
int main()
{
    int x = 15, y = 17, z;
    z = max(x, y);
    printf("%d", z);
    cout << z << endl; //cout和endl都是std命名空间的，必须引用了才能用；printf不需要
}