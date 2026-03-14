#include<iostream>
class A{
    int a;
    int *b =NULL;
    public :
    A(){
        b = new int();
    }
    void init(int x, int y){
        a =x;
        *b = y;
    }
    void change(int z)
    {
        *b = z;
    }
    void print(){
        std::cout<<a<<*b<<std::endl;
    }
    ~A(){
        delete b;
    }
    
};
int main(){
    A a1;
    a1.init(20,30);
    a1.print();
    A a2 = a1;
    a2.print();
    a2.change(40);
    a2.print();
    a1.print();
    return 0;
    
}