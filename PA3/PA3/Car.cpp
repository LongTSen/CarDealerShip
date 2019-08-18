//
//  Car.cpp
//  PA3
//
//  Created by LongSen on 8/2/19.
//  Copyright © 2019 LongSen. All rights reserved.
//

#include "Car.hpp"
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
Car::Car(){};
Car::Car(string vVIN,string vMake,string vModel,int vYear,double vPrice)
{
    VIN = vVIN;
    make = vMake;
    model = vModel;
    year = vYear;
    price = vPrice;
}

string Car::getVIN()
{
    return VIN;
    
}

string Car::getMake()
{
    return make;
}

string Car::getModel()
{
    return model;
}

int Car::getYear()
{
    return year;
}

double Car::getPrice()
{
    return price;
}


ostream& operator<<(ostream& osc,const Car& cars)
{
    osc<<cars.VIN<<endl;
    osc<<cars.make<<endl;
    osc<<cars.model<<endl;
    osc<<cars.year<<endl;
    osc<<fixed<<setprecision(2)<<cars.price<<endl;
    return osc;
}


