#include<iostream>
#include<vector>
using namespace std;
int main(){
// Vector initilization with 20 size default value with 0
// Note : Range Based Loop we can;t intilized the Value it will cause issue to resolve that
    vector<int>v1(20);
    for(int a1:v1){
        cout<<a1<<std::endl;
        //v1.push_back(a1);
    }
    // To file that Vector we can use TRaditional for loop to intilized the Vector
    for(int i =0; i<20; i++){
        v1.push_back(i);
    }
    // After Fille We are Print the Updated list of Array
    for(int a2:v1){
        std::cout<<a2<<std::endl;
    }
    v1.push_back(25);
     for(int a2:v1){
        std::cout<<a2<<std::endl;
    }
    std::cout<<v1.max_size()<<std::endl;
    std::cout<<v1.size()<<std::endl;
    std::cout<<v1.capacity()<<std::endl;
    std::cout<<v1.front()<<std::endl;
    v1.front() = 10;
    std::cout<<v1.front()<<std::endl;
    v1. back() = 100;
    std::cout<<v1.back()<<std::endl;
    for(int a3:v1){
        std::cout<<a3<<std::endl;
    }
    /*
    Front, Back, clear, Empty, Swap 

    */
    return 0;
}