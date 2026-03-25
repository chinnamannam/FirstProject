#include<iostream>
#include"studentinformation.h"

void addnewStudent(){
    for(int i =0;i<100;i++){
        if(s[i].name==""){
            std::cout<<"Enter the name of the student: ";
            std::cin>>s[i].name;
            std::cout<<"Enter the father name of the student: ";
            std::cin>>s[i].fatherName;
            std::cout<<"Enter the mother name of the student: ";
            std::cin>>s[i].motherName;
            std::cout<<"Enter the age of the student: ";
            std::cin>>s[i].age;
            std::cout<<"Enter the Aadhar number of the student: ";
            std::cin>>s[i].AadharNumber;
            std::cout<<"Enter the DOB of the student: ";
            std::cin>>s[i].DOB;
            std::cout<<"Enter the Gender of the student: ";
            std::cin>>s[i].gender;
            std::cout<<"Student added successfully."<<std::endl;
            break;
        }
    }
}