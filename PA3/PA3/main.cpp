

#include <iostream>
#include "Dealer.hpp"
#include "function.hpp"
#include  <vector>
#include "Car.hpp"
#include "ValidationInput.hpp"

int main(int argc, const char * argv[]) {
    vector<Dealer> dealers{};
    int choice;
    readFile(dealers);
    do {
        displayMenu();
        choice = getIntNumber();
        switch (choice) {
            case 1:
                readFile(dealers);
                opt1();
                break;
            case 2:
                opt2(dealers);
                break;
            case 3:
                opt3(dealers);
                break;
            case 4:
                opt4(dealers);
                break;
            case 5:
                opt5(dealers);
                break;
            case 6:
                writeFile(dealers);
                break;
            case 7:
                cout<<"Exist"<<endl;
                break;
            default:
                cout<<"Invalid choice"<<endl;
                break;
        }
    } while (choice!=7 );
    return 0;
}
