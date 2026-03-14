#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int>l;
    // Insertion at begging of the list
    l.insert(l.begin(),100);
    // instertion at end of the list
    l.insert(l.end(),1000);
    // Range based loop print
    for(int v:l){
        //std::cout<<v<<std::endl;
    }
    // Another way of Insertion in List
    l.push_front(100);
    l.push_back(1000);
    for(int W:l){
        //std::cout<<W<<std::endl;
    }
    //Remove First and Last element in the List
   l.pop_back();
   l.pop_front();
      for(int X:l){
       std::cout<<X<<std::endl;
    }
    list<int>l2 ={10,20,30,40,50,60};
    l2.insert(l2.begin(),l.begin(),l.end());
    for(int Y:l2){
        std::cout<<Y<<std::endl;
    }
    return 0;
}