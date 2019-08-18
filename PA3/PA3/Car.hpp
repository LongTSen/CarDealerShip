//
//  Car.hpp
//  PA3
//
//  Created by LongSen on 8/2/19.
//  Copyright © 2019 LongSen. All rights reserved.
//

#ifndef Car_hpp
#define Car_hpp

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Car
{
private:
    string VIN;
    string make;
    string model;
    int year;
    double price;
public:
    Car();
    Car(string vVIN,string vMake,string vModel,int vYear,double vPrice);
    string getVIN();
    string getMake();
    string getModel();
    int getYear();
    double getPrice();
    void setVIN(string);
    void setMake(string);
    void setModel(string);
    void setYear(int);
    void setPrice(double);
    friend ostream& operator<<(ostream&,const Car&);
    
};

#endif /* Car_hpp */
