#include <iostream>
#include <time.h>
#include <fstream>
#include <bits/stdc++.h>
#define SIZE 100000

using namespace std;

/*
to swap contents of two pointers
*/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
to find a pivot & divide the given array into two arrays, greater & smaller than pivot
*/
int partition(int arr[], int lb, int ub)
{
    // taking first element as pivot
	int pivot = arr[lb];

    // s & e being the start & end of the array
	int s = lb;
	int e = ub;

    // until s & e dont cross each other
	while(s < e)
	{
        // until s finds an element greater than pivot
		while(arr[s] <= pivot)
			s++;

        // until e finds an element smaller / equal to pivot
		while(arr[e] > pivot)
			e--;

        // if s & e haven't crossed each other
		if(s < e)
			swap(&arr[s], &arr[e]);
	}

    // after s & e crossed, swap start with end
	swap(&arr[lb], &arr[e]);
    
    // returning dividing point
	return e;
}

/*
recursive method to apply quick sort
params are array, start & end index
*/
void QuickSort(int a[], int lb, int ub)
{
    // start should be smaller than end index
	if(lb < ub)
	{
        // the dividing point
		int loc = partition(a, lb, ub);

        // sorting the resultant 2 arrays
		QuickSort(a, lb, loc-1);
		QuickSort(a, loc+1, ub);
	}
}

/*
to populate the array with random nums
*/
void populate_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100 + 1;
}

/*
to display the array
*/
void display_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";

    cout << endl << endl;
}

int main()
{
    // declaring clock variables
    clock_t start_time, end_time;

    // file stream
    ofstream myfile;
    myfile.open("QuickSortWorst.csv");

    // columns header
    myfile << "N,Time\n";

    for (int i = 10; i < SIZE; i += 10)
    {
        int arr[i];

        // populating array
        populate_array(arr, i);

        sort(arr, arr + i, greater<int>());

        start_time = clock();

        // sorting the array
        QuickSort(arr, 0, i - 1);

        end_time = clock();

        cout << i << "," << double(end_time - start_time) / CLOCKS_PER_SEC << endl;

        myfile << i << "," << double(end_time - start_time) / CLOCKS_PER_SEC << endl;
    }

    myfile.close();

    return 0;
}