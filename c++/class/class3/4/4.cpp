#include"4.h"
#include"iostream"
using namespace std;
void Cuboid::setValue(){
    cout<<"长:";
    cin>>length;
    cout<<"宽:";
    cin>>width;
    cout<<"高:";
    cin>>height;
}
void Cuboid::calculate(){
    cuboid=length*width*height;
}
void Cuboid::prin(){
    cout<<cuboid<<endl;
}
