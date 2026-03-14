#include<iostream>
int add(int *a, int *b);
int main(){
    int a=10;
    int b =20;
    std::cout<<a<<b<<std::endl;
    add(&a,&b);
    std::cout<<a<<b<<std::endl;
    return 0;
}
int add(int *a, int *b){
    (*a)++;
    (*b)++;
    std::cout<<*a<<*b<<std::endl;
    return *a+*b;
}
