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
class B : virtual public A{
};
class C: virtual public A{
};
class D : public B, public C{
};

int main(){
  D d1;
  d1.fun();
  d1.display();
  return 0;
}