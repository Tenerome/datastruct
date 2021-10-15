#include"5.h"
#include"iostream"
#define PI 3.14
using namespace std;
 
float Circle::getArea(){
    return PI*radius*radius;
}
void Circle::setValue(float radius){
    this->radius=radius;
}