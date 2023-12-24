#pragma once

#include <iostream>
#include <fstream>
#include "Address.cpp"
using namespace std;

//concrete class
class Student{
private:
    //data memb*ers
    string name;
    Address address; //composition

public:
    //constructors
    Student():name("unknown"){}
    Student(string name):name(name){}
    Student(string name, Address address):name(name), address(address){}
    Student(string name, string street, string city):name(name), address(street, city){}
    
    ~Student(){
      
    }
    //setter and getter methods
    Address getAddress(){
        return address;
    }
    void setAddress(Address address){
        this->address=address;
    }
    void setAddress(string street, string city){
        address.setStreet(street);
        address.setCity(city);
    }
    string getName(){
        return name;
    }
    void setName(string name){
        this->name=name;
    }
    //method members
    virtual void display(){
        cout<<"Name:"<<name;
        address.display();
    }

    virtual void getStudent(){
        cout<<"Enter name: ";
        cin>>name;
        address.getAddress();
       
    }
 

    
};
