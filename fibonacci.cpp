#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

/*
calculates fibonacci number @ 'num' index using iteration
*/
int fibonacci_rec(int num)
{
    // returns 0 & 1 @ o & 1 index
    if (num == 0 || num == 1)
    {
        return num;
    }

    // calculates fibonacci number
    else
    {
        return fibonacci_rec(num - 1) + fibonacci_rec(num - 2);
    }
}

/*
calculates fibonacci number @ 'num' index using recursion
*/
int fibonacci_itr(int num)
{
    // array to store fibonacci numbers
    int array[num + 2];

    // predefined 1st 2 nums of series
    array[0] = 0;
    array[1] = 1;

    // calculating remaining numbers
    for (int i = 2; i <= num; i++)
    {
        array[i] = array[i - 1] + array[i - 2];
    }

    return array[num];
}

int main()
{
    // opening file stream
    ofstream myfile1;
    myfile1.open("fibonacci_itr.csv");

    // headers for the columns of excel file
    myfile1 << "N,Time\n";

    cout << "For iterative function: " << endl;

    // to measure timings
    clock_t start_time;
    clock_t end_time;

    for (int i = 1; i <= 500000; i += 10)
    {
        // measuring time at certain points
        start_time = clock();
        fibonacci_itr(i);
        end_time = clock();

        // writing it into the csv file
        myfile1 << i << "," << double(end_time - start_time) / CLOCKS_PER_SEC << endl;

        // displaying for the user
        cout << i << "," << double(end_time - start_time) / CLOCKS_PER_SEC << endl;
    }

    // closing the file stream
    myfile1.close();

    // opening another file stream
    ofstream myfile2;
    myfile2.open("fibonacci_rec.csv");

    // headers for the columns of excel file
    myfile2 << "N,Time\n";

    cout << "\nFor recursive function: " << endl;

    for (int i = 1; i <= 50; i++)
    {
        // measuring time
        start_time = clock();
        fibonacci_rec(i);
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