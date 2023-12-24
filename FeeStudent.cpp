
#pragma once

#include <iostream>
#include "Student.cpp"
#include "Payoff.cpp"
using namespace std;

class FeeStudent: public Student, Payoff{
private:
    double fee;
public:
    FeeStudent():Student(), fee(0){}
    FeeStudent(string name, Address address, double fee):Student(name, address), fee(fee){}
    
    //setter and getter
    double getFee(){
        return fee;
    }

    double getPayoff(){
        return fee;
    }
    
    void display(){
        Student::display();
        cout<<" Fee:"<<fee;
    }
    void getStudent(){
        Student::getStudent();
        cout<<"Enter Student fee: ";
        cin>>fee;
    }
};

