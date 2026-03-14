#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int>l={10,20,30,40,50,60};
    list<int>l1 ={70,80,90,100};
    // Copying l1 list element into l at the Begin of the list
    l.splice(l.begin(),l1);
   for(int C:l){
        std::cout<<C<<std::endl;
    }
    // Copying l1 list element into l at the end of the list.
    l.splice(l.end(),l1);
    for(int W:l){
        std::cout<<W<<std::endl;
    }
    l1.splice(l1.begin(),l);
    for(int Z:l1){
        std::cout<<Z<<std::endl;
    }
    return 0;
}