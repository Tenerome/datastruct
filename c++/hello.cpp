//c++中自带max函数  （std::max<int>(const int &__a, const int &__b)），不能用整个std命名空间
#include <iostream>
using namespace std;
int main(){
    int a=20,b=10;
    int d=max(a,b);
    printf("%d",d);
    
}