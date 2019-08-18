//
//  Dealer.cpp
//  PA3
//
//  Created by LongSen on 7/23/19.
//  Copyright © 2019 LongSen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "function.hpp"
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "Dealer.hpp"
#include <vector>
#include <string>
#include <sstream>
#include "Car.hpp"


using namespace std;

Dealer::Dealer(string dDealerName,int dNumber,int dNmberOfCar)
{
    dealerName = dDealerName;
    dealerNumber = dNumber;
    numberOfCars = dNmberOfCar;
    carArrayPtr = new Car[numberOfCars];
}
Dealer::Dealer(){};


void Dealer::setArrayOfCars(string a,string b,string c,int d,double e,int cout)
{
    carArrayPtr[cout]=Car(a, b, c, d, e);
}

string Dealer::getDealerName()
{
    return dealerName;
}

int Dealer::getDealearNUmber()
{
    return dealerNumber;
}

int Dealer::getNUmberOfCars()
{
    return numberOfCars;
}

void Dealer::insNumOfCars()
{
    numberOfCars++;
    Car* newArr = new Car[numberOfCars];
    copy(carArrayPtr, carArrayPtr + min(numberOfCars-1, numberOfCars), newArr);
    delete [] carArrayPtr;
    carArrayPtr = newArr;
}

Car * Dealer::getCars()
{
    return carArrayPtr;
}

ostream& operator<<(ostream& os,const Dealer& dealers)
{
    os<<dealers.dealerName<<endl;
    os<<dealers.dealerNumber<<endl;
    return os;
}

