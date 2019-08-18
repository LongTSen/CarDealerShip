//
//  function.cpp
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
#include "ValidationInput.hpp"

using namespace std;

void displayMenu()
{
    cout<< "1.Read Dealers and Cars from file\n2.Display Dealers\n3.Choose a Dealer Number, Display Cars\n4.Choose a Dealer Number, Add Car\n5.Choose a Dealer, Sort cars by VIN (EXTRA CREDIT)\n6.Write Dealers and Cars to file (EXTRA CREDIT)\n7.Exit\n";
}

void opt1()
{
    string line;
    ifstream infile;
    infile.open("DATA.txt");
    if (!infile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    while (!infile.eof()) {
        getline(infile,line);
        if(line.length()==0)
        {
            infile.close();
        }
        cout<<line<<endl;
    }
    infile.close();
}

void opt2(vector<Dealer> &dealers)
{
    cout<<dealers.size();
    for(Dealer dealer : dealers)
    {
        cout<<dealer;
        cout<<"Number of Cars: "<<dealer.getNUmberOfCars()<<"\n"<<endl;
    }
}

void opt3(vector<Dealer> &d)
{
    int dealerNumber;
    cout<<"Enter Dealer Number"<<endl;
    dealerNumber = getIntNumber();
    bool find = false;
    for (int i=0;i<d.size();i++)
    {
        if(dealerNumber==d[i].getDealearNUmber())
        {
            cout<<"Number Of Cars: "<<d[i].getNUmberOfCars()<<endl;;
            for(int a=0;a<d[i].getNUmberOfCars();a++)
            {
            cout<<*(d[i].getCars()+a)<<endl;

                find = true;}
        }
    }
    if (find==false)
    {
        cout<<dealerNumber<<" doesn't exist"<<endl;
    }
}

void opt4(vector<Dealer> &dealer)
{
    bool addCar=false;
    string line,dealerName,VIN,make,model;
    int dealerNumber,numOfCar,year;
    double price;
    cout<<"Enter Dealer Number"<<endl;
    cin>>dealerNumber;
    for(int i=0;i<dealer.size();i++)
    {
        if(dealerNumber==dealer[i].getDealearNUmber())
        {
            cout<<dealer[i].getNUmberOfCars()<<endl;;
            cout<<"Enter VIN"<<endl;
            cin>>VIN;
            cout<<"Enter Make"<<endl;
            cin>>make;
            cout<<"Enter model"<<endl;
            cin>>model;
            cout<<"Enter year"<<endl;
            year = getIntNumber();
            cout<<"Enter price"<<endl;
            price = getDouNumber();
            numOfCar=dealer[i].getNUmberOfCars();
            dealer[i].insNumOfCars();
            dealer[i].setArrayOfCars(VIN, make, model, year, price, numOfCar);
            addCar=true;
            cout<<"Add Car sucessfull"<<endl;
            cout<<dealer[i].getNUmberOfCars()<<endl;;
        }
    }
    if(addCar==false)
    {
        cout<<"Add Car unsucessfull"<<endl;
    }
}

void opt5(vector<Dealer> &dealer)
{
    int dealerNumber;
    cout<<"Enter Dealer Number"<<endl;
    dealerNumber = getIntNumber();
    for(int i=0;i<dealer.size();i++)
    {
        if(dealerNumber==dealer[i].getDealearNUmber())
        {
            sortCar(dealer[i].getCars(), dealer[i].getNUmberOfCars());
        }
    }
}

void sortCar(Car *cars,int size)
{
    int startScan, minIndex;
    string minValue;
    Car tempCar[1];
    for(startScan=0;startScan<(size-1);startScan++)
    {
        minIndex = startScan;
        minValue = cars[startScan].getVIN();
        tempCar[0] = cars[startScan];
        for(int index = startScan+1;index<size;index++)
        {
            if (cars[index].getVIN()<minValue)
            {
                minValue = cars[index].getVIN();
                tempCar[0] = cars[index];
                minIndex = index;
            }
        }
        cars[minIndex] = cars[startScan];
        cars[startScan] = tempCar[0];
    }
    cout<<"Sorted Cars by VIN Successfully"<<endl;
}

void readFile(vector<Dealer> &d)
{
    d.clear();
    string line,dealerName,VIN,make,model;
    int dealerNumber,numOfCar,year;
    double price;
    ifstream infile;
    infile.open("DATA.txt");
    if (!infile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    while (!infile.eof()) {
        getline(infile,line);
        if(line.length()==0)
        {
            break;
        }
        dealerName = line;
        getline(infile,line);
        istringstream iss (line);
        iss >> dealerNumber;
        getline(infile,line);
        istringstream iss1 (line);
        iss1 >> numOfCar;
        d.push_back(Dealer(dealerName, dealerNumber, numOfCar));
        for(int i=0;i<numOfCar;i++)
        {
            getline(infile,line);
            VIN = line;
            getline(infile,line);
            make = line;
            getline(infile,line);
            model = line;
            getline(infile,line);
            istringstream iss (line);
            iss >> year;
            getline(infile,line);
            istringstream iss1 (line);
            iss1 >> price;
            d.back().setArrayOfCars(VIN, make, model, year, price, i);
        }
    }
    infile.close();
}

void writeFile(vector<Dealer> &dealer)
{
    ofstream outfile;
    outfile.open("DATA.txt");
    {
        cout<<dealer.size()<<endl;
        for(int i=0;i<dealer.size();i++)
        {
            outfile<<dealer[i].getDealerName()<<endl;;
            outfile<<dealer[i].getDealearNUmber()<<endl;
            outfile<<dealer[i].getNUmberOfCars()<<endl;
            for(int a=0;a<dealer[i].getNUmberOfCars();a++)
            {
                outfile<<*(dealer[i].getCars()+a);
            }
        }
        outfile.close();
    }
}
