#include<iostream>
class A{
    int x;
    public :
    int y,z;
    void fun(){
        std::cin>>x>>y>>z;
    }
    void display(){
        std::cout<<x<<y<<z<<std::endl;
    }
};
class B{
    int a;
    public :
    int b,c;
    void fun1(){
        std::cin>>a>>b>>c;
    }
    void display1(){
        std::cout<<a<<b<<c<<std::endl;
    }
};
class C: public A, public B{

};
int main(){
  C c1;
  c1.fun();
  c1.display();
  c1.fun1();
  c1.display1();
  return 0;
}