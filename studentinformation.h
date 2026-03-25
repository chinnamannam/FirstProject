#include<iostream>
#include<string.h>
#pragma once

struct student{
    std::string name;
    std::string fatherName;
    std::string motherName;
    int age;
    std::string AadharNumber;
    std::string DOB;
    std::string gender;
};

extern struct student s[100];
void addnewStudent();
void removeStudent();
void searchStudent();
void studentDetails();
void updateStudent();
void totalStudents();