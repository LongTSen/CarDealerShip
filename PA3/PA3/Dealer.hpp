//
//  Dealer.hpp
//  PA3
//
//  Created by LongSen on 7/23/19.
//  Copyright © 2019 LongSen. All rights reserved.
//

#ifndef Dealer_hpp
#define Dealer_hpp
#include <iostream>
#include <stdio.h>
#include <vector>
#include "Car.hpp"

using namespace std;

class Dealer
{
private :
    string dealerName;
    int dealerNumber;
    int numberOfCars;
    Car *carArrayPtr= nullptr;

public :
    Dealer();
    Dealer(string dDealerName,int dNumber,int numberOfCars);
    void setArray();
    void setDealerName(string);
    void setDealerNumber(int);
    void setNumberOfCars(int numberOfCars);
    void setArrayOfCars(string,string,string,int,double,int);
    string getDealerName();
    int getDealearNUmber();
    int getNUmberOfCars();
    Car *getCars();
    void printCars();
    void insNumOfCars();
    friend ostream& operator<<(ostream& os,const Dealer& dealers);
};



#endif /* Dealer_hpp */
