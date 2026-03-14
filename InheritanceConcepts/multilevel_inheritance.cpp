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
class B : public A{
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
class C: public B{
        int e;
    public :
    int f,g;
    void fun2(){
        std::cin>>e>>f>>g;
    }
    void display2(){
        std::cout<<e<<f<<g<<std::endl;
    }

};
int main(){
  C c1;
  c1.fun();
  c1.display();
  c1.fun1();
  c1.display1();
  c1.fun2();
  c1.display2();
  return 0;
}