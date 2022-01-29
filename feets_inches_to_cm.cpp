#include <iostream>

using namespace std;

int main(){

    // declaring variables
    double feet, inches, total, cm;
    
    // taking input from user
    cout << "\nEnter the feet part of length, press 'Enter' then enter inches (if any): \n";
    cin >> feet;
    cin >> inches;

    // converting length into total inches
    total = inches + feet * 12;

    // converting length into centimetres
    cm = total * 2.54;

    // displaying required output
    cout << endl << feet << "\' " << inches << "\'\' --> " << cm << " cm\n";

} // end of main method