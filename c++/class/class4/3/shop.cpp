//课后题 第三章9
#include"iostream"
using namespace std;

class shop{
    static float discount;
    static float sum;
    static int n;
    
    int quantity;
    float price;

    public:
    void cal();
    static float average();
    static void display();
    shop(int,float);
};
//shop函数实现
float shop::discount=0.85;
float shop::sum=0;
int shop::n=0;
shop::shop(int quantity,float price){
    this->quantity=quantity;
    this->price=price;
}
float shop::average(){
     return sum/n;
}
void shop::cal(){
    if(shop::quantity>10)
        price*=0.98;
    sum+=price*quantity*discount;
    n+=quantity;
}
void shop::display(){
    cout<<"总价:"<<sum<<endl<<"平均值:"<<average();
}
//函数
int main(){
    shop sh[3]={
        shop(5,23.5),
        shop(12,24.56),
        shop(100,21.5)
    };
    sh[0].cal();
    sh[1].cal();
    sh[2].cal();
    sh[2].display();

}