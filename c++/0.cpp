#include <iostream>
using std::cout;
using std::endl; //std中自带了max函数（std::max<int>(const int &__a, const int &__b)），不能用整个std命名空间
template<typename T>
T max(T a,T b){
if (a>b)
    return a;
else 
    return b;
}

int main(){
    int x=10;
    int y=20;
    int z;
    float h=10.9,m=12.0,n;
    z=max(x,y);
    n=max(h,m);
    printf("%d%f",z,n);
    //cout<<z<<endl<<n<<endl;
    return 0;
}
