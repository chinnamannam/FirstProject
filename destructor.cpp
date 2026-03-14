#include<iostream>
class A{
    public :
        A(){
        std::cout<<"BaseClass Constr"<<std::endl;
    }
   Virtual  ~A(){
        std::cout<<"BaseClass destr"<<std::endl;
    }
};
class B: public A{
    public :
            B(){
        std::cout<<"DerivedClass Const"<<std::endl;
    }
        ~B(){
        std::cout<<"DerivedClass destruc"<<std::endl;
    }

};
int main(){
  B b;
  A *a = &b;
}