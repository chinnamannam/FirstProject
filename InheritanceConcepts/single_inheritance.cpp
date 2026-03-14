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
// Single Inheritance
class B : public A{

};
int main(){
  B b1;
  b1.fun();
  b1.display();
  return 0;
}