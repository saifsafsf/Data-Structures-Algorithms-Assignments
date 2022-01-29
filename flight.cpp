#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Test
{

// declaring private variables
int flightNo;
string destination;
float distance, fuel;

float calFuel(){

    if (distance <= 1000)
        return 500;

    else if (distance <= 2000)
        return 1100;

    else
        return 2200;

} // end of calFuel() method

public:
    int feedInfo(){

        // flight number input
        cout << "\nEnter flight number: ";
        cin >> flightNo;

        // destination input
        cout << "\nEnter destination of flight: ";
        cin >> destination;

        // distance input
        cout << "\nEnter distance of flight: ";
        cin >> distance;

        // fuel calculation
        fuel = calFuel();

        return 0;

    } // end of feedInfo method

    void showInfo(){

        // displaying all data membres with proper message
        cout << "\nFlight Number: " << flightNo << endl;
        cout << "Distance covered: " << distance << " units" << endl;
        cout << "Fuel used: " << fuel << " units" << endl;
        cout << "Destination: " << destination << endl;

    } // end of showInfo method

}; // end of the class Test

int main(){

    Test obj;
    obj.feedInfo();
    obj.showInfo();
    getch();
    return 0;

} // end of main method