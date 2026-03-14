#include<iostream>
class A{
    int a;
    int b,c;
    public:
    A(){
        a =20;
    }
    A(int x, int y){
        b = x;
        c = y;
    }
    void display(){
        std::cout<<a<<b<<c<<std::endl;
    }
};
int main(){
    A a1;
    A a2(20,30);
    a1.display();
    a2.display();
    return 0;

}