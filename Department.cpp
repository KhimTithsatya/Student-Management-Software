#pragma once

#include <iostream>
#include "Student.cpp"
using namespace std;

class Department{
private:
    string name;
    Student* student; //aggregation
    
    //Employee* employees=new Employee[20];
    
public:
    Department():name("unknown"), student(nullptr){}
    Department(string name, Student* student):name(name), student(student){}
    
//    ~Department(){
//        cout<<"Destroyed department"<<endl;
//    }
    //setter and getter
    void setStudent(Student* student){
        if(this->student!=nullptr){
            delete student;
        }
        this->student=student;
    }
    void setStudent(string name, Address address){
        if(this->student!=nullptr){
            delete student;
        }
        this->student=new Student(name, address);
    }
    
    void display(){
        cout<<"Name:"<<name<<endl;
        student->display();
        
    }
    
};

