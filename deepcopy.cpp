#include<iostream>
class A{
    int a;
    int *p = NULL;
    public :
    A(){
        p = new int();
    }
    void fun(int x, int y){
        a = x;
        *p = y;
    }
    void change(int z){
        *p = z;
    }
    void print(){
        std::cout<<a<<*p<<std::endl;
    }
    A(const A &obj){
        a = obj.a;
        p = new int();
        *p = *(obj.p);
    }
    ~A(){
        delete p;
    }
};
int main(){
    A a1;
    a1.fun(25,35);
    a1.print();
    A a2 = a1;
    a2.print();
    a2.change(40);
    a2.print();
    a1.print();
    return 0;
}