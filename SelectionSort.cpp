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

void SelectionSort1(int a[], int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		int min = i;
		for(int j = i + 1; j < n; j++)
		{
			if(a[j] < a[min])
			{
				min = j;
			}
		}
		if(min != i)
			swap(&a[i], &a[min]);
	}
}

int main()
{
    int arr[SIZE];
    clock_t start_time, end_time;

    // file stream
    ofstream myfile1;
    myfile1.open("SelectionSort.csv");

	cout << "Selection Sort: \n\n";
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
        SelectionSort1(arr, i);

        end_time = clock();

        // displaying computing time
        cout << i << "," << double(end_time - start_time) / CLOCKS_PER_SEC << endl;

        // writing into file
        myfile1 << i << "," << double(end_time - start_time) / CLOCKS_PER_SEC << endl;
    }

    myfile1.close();

    // checking the sorted array
    // for (int i = 0; i < SIZE; i++)
    // {
    //     cout << arr[i] << endl;
    // }

    return 0;
}