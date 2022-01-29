#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

/*
calculates factorial of a number using recursion
*/
int factorial_rec(int num)
{
    // gives 0 & 1 @ 0 & 1
    if (num == 0 || num == 1)
    {
        return num;
    }

    // calculating factorial
    else
    {
        return num * factorial_rec(num - 1);
    }
}

/*
calculates factorial using iteration
*/
int factorial_itr(int num)
{
    // to store final answer
    int factorial = 1;

    // calculating factorial
    for (int i = 1; i <= num; i++)
    {
        factorial *= i;
    }

    return factorial;
}

int main()
{
    // opening file stream
    ofstream myfile1;
    myfile1.open("factorial_itr.csv");

    // headers for the excel file
    myfile1 << "N,Time\n";

    cout << "For iterative function: " << endl;

    // to measure time
    clock_t start_time;
    clock_t end_time;

    for (int i = 1; i <= 1000000; i += 10)
    {
        // measuring at certain points
        start_time = clock();
        factorial_itr(i);
        end_time = clock();

        // writing into the csv file
        myfile1 << i << "," << double(end_time - start_time) / CLOCKS_PER_SEC << endl;

        // displaying for the user
        cout << i << "," << double(end_time - start_time) / CLOCKS_PER_SEC << endl;
    }

    // closing the file stream
    myfile1.close();

    // opening next file stream
    ofstream myfile2;
    myfile2.open("factorial_rec.csv");

    // headers for the excel file
    myfile2 << "N,Time\n";

    cout << "\nFor recursive function: " << endl;

    for (int i = 1; i <= 40000; i += 10)
    {
        // measuring at certain points
        start_time = clock();
        factorial_rec(i);
        end_time = clock();

        // writing into csv file
        myfile2 << i << "," << double(end_time - start_time) / CLOCKS_PER_SEC << endl;

        // displaying for the user
        cout << i << "," << double(end_time - start_time) / CLOCKS_PER_SEC << endl;
    }

    // closing & returning
    myfile2.close();
    return 0;
}