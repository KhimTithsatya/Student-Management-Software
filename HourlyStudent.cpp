
#pragma once

#include <iostream>
#include "Student.cpp"
#include "Payoff.cpp"
using namespace std;

class HourlyStudent: public Student, public Payoff{
private:
    double rate;
    double hour;
public:
    HourlyStudent():Student(), rate(0), hour(0){}
    HourlyStudent(string name, Address address, double rate, double hour):Student(name, address), rate(rate), hour(hour){}
    
    
    double getPayoff(){
        return rate*hour;
    }

    void display(){
        Student::display();
        cout<<" Rate:"<<rate<<" Hour:"<<hour;
    }
    void getStudent(){
        Student::getStudent();
        cout<<"Enter rate: ";
        cin>>rate;
        cout<<"Enter hour: ";
        cin>>hour;
    }
};
