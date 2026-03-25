#include<iostream>
#include"studentinformation.h"

student s[100];
void studentDetails(){
int numberOfStudents = 0;
    for(int i=0; i<100; i++){
            if(s[i].name !=""){
            std::cout<<"**********Student details in the class**********"<<std::endl;
            std::cout<<"Name: "<<s[i].name<<std::endl;
            std::cout<<"Father Name: "<<s[i].fatherName<<std::endl;
            std::cout<<"Mother Name: "<<s[i].motherName<<std::endl;
            std::cout<<"Age: "<<s[i].age<<std::endl;
            std::cout<<"Aadhar Number : "<<s[i].AadharNumber<<std::endl;
            std::cout<<"DOB: "<<s[i].DOB<<std::endl;
            std::cout<<"Gender: "<<s[i].gender<<std::endl;
            numberOfStudents++;
            }
        }
        if(numberOfStudents == 0){
            std::cout<<"No student in the class."<<std::endl;
        }
}
void totalStudents(){
    int numberOfStudents = 0;
    for(int i=0; i<100; i++){
        if(s[i].name !=""){
            numberOfStudents++;
        }
    }
    std::cout<<"Total number of students in the class: "<<numberOfStudents<<std::endl;
}