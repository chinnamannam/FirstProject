#include<iostream>
class A{
    int a,b;
    public:
    A(int x,int y){
        a =x;
        b =y;
    }
    void print(){
        std::cout<<a<<b<<std::endl;
    }
    // Defined own Copy Construtor
    A(const A &obj){
        a = obj.a;
        b = obj.b;
    }
};
int main(){
    A a1(25,35);
    a1.print();
    // own Copy COnstructr Called perform Shall copy
    A a2 = a1;
    // Compiler Genrated Copy Assignment Operator will be Called 
    a2 = a1;
    a2.print();
}