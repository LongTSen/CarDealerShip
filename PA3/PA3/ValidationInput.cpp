//
//  ValidationInput.cpp
//  PA3
//
//  Created by LongSen on 8/14/19.
//  Copyright © 2019 LongSen. All rights reserved.
//

#include "ValidationInput.hpp"
#include <iostream>
#include <stdio.h>
#include <sstream>
using namespace std;

int getIntNumber()
{
    int number;
    string strInput = "";
    while (true)
    {
        cin>>strInput;
        stringstream myStream(strInput);
        if ( (myStream >> number && number>0) )
            break;
        cout << "Invalid input, please try again" << endl;
    }
    return number;
}

double getDouNumber()
{
    double douNumber;
    string strInput = "";
    while (true)
    {
        cin>>strInput;
        stringstream myStream(strInput);
        if ( (myStream >> douNumber && douNumber>0) )
            break;
        cout << "Invalid input, please try again" << endl;
    }
    return douNumber;
}
