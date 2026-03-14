using namespace std;
#include<iostream>
#include<vector>

int main(){
    // Initilization of a Vector
    vector<int>v1;
    // Intilization with Values
    vector<int>v2={10,20,30,40,5,06,0,70,80,90,100};
    // Initlization of a Vector with 10 Size Default Value was 0
    vector<int>v3(10);
    // Initlization of a Vector with 10 Size Values filled with 1
    vector<int>v4(10,1);
    // Inilization og Vector with String type size 3 assigned with "Hi."
    vector<string>v5(3,"Hi");
    // Range Based For Loop
    for(int a2:v2){
        std::cout<<a2<<std::endl;
    }
    // Iterator Based For Loop
    vector<int>::iterator it;
    for(it = v2.begin(); it!= v2.end(); it++){
        std::cout<<*it<<std::endl;
    }
    // Iterator Based Reverese for Loop
    vector<int>::reverse_iterator rit;
    for(rit = v2.rbegin(); rit!=v2.rend(); rit++){
        std::cout<<*rit<<std::endl;
    }
    for(int a3:v3){
        std::cout<<a3<<std::endl;
    }
    for(int a4:v4){
        std::cout<<a4<<std::endl;
    }
    for(string a5:v5){
        std::cout<<a5<<std::endl;
    }
    return 0;
}