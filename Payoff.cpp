#pragma once

#include<iostream>
using namespace std;

//Abstract class
class Payoff{
public:
    virtual double getPayoff()=0;


};