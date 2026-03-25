#include<iostream>
#include"studentinformation.h"

int main(){
    int input;
    while(true){
        std::cout<<"*****************student management system**********************"<<std::endl;
        std::cout<<"1.Students Details."<<std::endl;
        std::cout<<"2.Add Student Details."<<std::endl;
        std::cout<<"3.Delete Student Details."<<std::endl;
        std::cout<<"4.Update Student Details."<<std::endl;
        std::cout<<"5.Search Student Details."<<std::endl;
        std::cout<<"6.close the System."<<std::endl;
        std::cin>>input;
        switch(input){
            case 1:
                std::cout<<"Students details in the class"<<std::endl;
                studentDetails();
                break;
            case 2:
                std::cout<<"Add new student in the class"<<std::endl;
                addnewStudent();
                break;
            case 3:
                std::cout<<"Remove student from the class."<<std::endl;
                removeStudent();
                break;
            case 4:
                std::cout<<"Update the Student details in the class."<<std::endl;
                updateStudent();
                break;
            case 5:
                std::cout<<"Search student in the class ."<<std::endl;
                searchStudent();
                break;
            case 6:
                std::cout<<"Exit the menu."<<std::endl;
                return 0;
            default:
                std::cout<<"not valid option"<<std::endl;
                break;
        }
    }
    return 0;
}

