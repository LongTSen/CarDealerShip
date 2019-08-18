//
//  function1.hpp
//  PA3
//
//  Created by LongSen on 7/26/19.
//  Copyright © 2019 LongSen. All rights reserved.
//

#ifndef function_hpp
#define function_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Dealer.hpp"
#include "Car.hpp"

using namespace std;
void opt1();//hj
void opt2(vector<Dealer> &dealers);
void readFile(vector<Dealer> &d);
void displayMenu();
void opt3(vector<Dealer> &);
void opt4(vector<Dealer> &);
void opt5(vector<Dealer> &);
void sortCar(Car*,int size);
void writeFile(vector<Dealer> &);





#endif /* function1_hpp */

