#include<iostream>
int add(int& a);
int main(){
    int a=10;
    std::cout<<a<<std::endl;
    add(a);
    std::cout<<a<<std::endl;
    return 0;
}
int add(int& a){
    a++;
    std::cout<<a<<std::endl;
    return a;
}