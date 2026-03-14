#include<iostream>
class A{
    // Private class constructor
    A(){
        std::cout<<"private constrctor"<<std::endl;
    }
    public:
    //  we have to use Static function to Access the private Construtor. otherwise it will through Error.
    static void display();
};
void A::display(){
    A();
}
int main(){
    A::display();
    return 0;

}