#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,int>m1;
    map<int,int>m2 ={{1,2},{2,3},{3,4}};
    for(auto it = m2.begin();it!=m2.end();it++){
        std::cout<<it->first<<" "<<it->second<<std::endl;
    }
    for(auto it2 = m1.begin();it2!=m1.end();it2++){

        std::cout<<it2->first<<" "<<it2->second<<std::endl;
    }
    
    return 0;
}