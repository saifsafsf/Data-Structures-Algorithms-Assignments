#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <bits/stdc++.h>
#define SIZE 10000

using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort1(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int main()
{
    int arr[SIZE];
    clock_t start_time, end_time;

    // file stream
    ofstream myfile1;
    myfile1.open("BubbleSort1.csv");

    cout << "Bubble Sort 1: \n\n";
    myfile1 << "N,Time\n";
    
    for(int i = 10; i < SIZE; i += 50)
    {
        // populating the array
        for (int i = 0; i < SIZE; i++)
        {
            arr[i] = (rand() % 100) + 1;
        }

        // measuring time
        start_time = clock();

        // sorting the array
        bubbleSort1(arr, i);

        end_time = clock();

        // displaying computing time
        cout << i << "," << double(end_time - start_time) / CLOCKS_PER_SEC << endl;

        // writing into file
        myfile1 << i << "," << double(end_time - start_time) / CLOCKS_PER_SEC << endl;
    }

    myfile1.close();

    return 0;
}