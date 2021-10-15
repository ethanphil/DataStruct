
#include "WhatToSort.h"
#include <chrono>
#include <iostream>

typedef std::chrono::high_resolution_clock Clock;


using namespace std;

TheArrays::TheArrays() 
{
    RandomizeAll();
}

void TheArrays::RandomizeAll()
{
    cout << "Randomizing Arrays" << endl;
    srand(time(NULL));
	for (int i = 0; i < 10; i++)
    {
       small[i] = rand()%20;
    }
    for (int i = 0; i < 100; i++)
    {
        schmedium[i] = rand()%200;
    }
    for (int i = 0; i < 500; i++)
    {
        medium[i] = rand()%1000;
    }
    for (int i = 0; i < 5000; i++)
    {
        large[i] = rand()%10000;
    }
    for (int i = 0; i < 25000; i++)
    {
        magnumxl[i] = rand()%50000;
    }
}

void TheArrays::BubbleSort(int arr[], int size)
{
    int temparr[size];
    std::copy(arr, arr + size, temparr);
    auto t1 = Clock::now();
    int i, temp;
    bool flag;
    while(true)
    {
        for(i = 0; i<size-1; i++) {
            if (temparr[i] > temparr[i+1])
            {
                temp = temparr[i];
                temparr[i] = temparr[i+1];
                temparr[i+1] = temp;
                flag = true;
            }
        }
        if (!flag)
        {
            break;
        }
        flag = false;
    }
    auto t2 = Clock::now();
    std::cout << "Delta t2-t1: " 
       << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() 
       << " nanoseconds" << std::endl;

}

void TheArrays::InsertionSort(int arr[], int size)
{
    int temparray[size];
    copy(arr, arr + size, temparray);
    auto t1 = Clock::now();
    int j, temp;
    for(int k=1; k<size; k++)
    {
        temp = temparray[k];
        j= k-1;
        while(j>=0 && temp <= temparray[j])
        {
            temparray[j+1] = temparray[j];
            j = j-1;
        }
        temparray[j+1] = temp;
    } 
    auto t2 = Clock::now();
    std::cout << "Delta t2-t1: " 
       << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() 
       << " nanoseconds" << std::endl;
}

void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[high];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) 
        {
            c[k] = arr[i];
            k++;
            i++;
        }
        else 
        {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    
    while (i <= mid) 
    {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) 
    {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++) 
    {
        arr[i] = c[i];
    }
}

void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high){
        //divide the array at mid and sort independently using merge sort
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        //merge or conquer sorted arrays
        merge(arr,low,high,mid);
    }
}

void TheArrays::MergeSort(int arr[], int size)
{
    int temparray[size];
    auto t1 = Clock::now();
    copy(arr, arr + size, temparray);
    
    // read input array and call mergesort
    merge_sort(temparray, 0, size-1);
    auto t2 = Clock::now();
    std::cout << "Delta t2-t1: " 
       << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() 
       << " nanoseconds" << std::endl;
}

// Quick sort
// Swap two elements - Utility function
void swap(int* a, int* b)
{
   int t = *a;
   *a = *b;
   *b = t;
}
// partition the array using last element as pivot
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++)
    {
            //if current element is smaller than pivot, increment the low element
            //swap elements at i and j
            if (arr[j] <= pivot)
            {
                i++; // increment index of smaller element
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
}
 
//quicksort algorithm
void quickSort(int arr[], int low, int high)
{
    if (low < high)
   {
        //partition the array 
        int pivot = partition(arr, low, high);
        //sort the sub arrays independently
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
   }
}

void TheArrays::QuickSort(int arr[], int size)
{
    int temparray[size];
    copy(arr, arr + size, temparray);
    auto t1 = Clock::now();
    quickSort(temparray, 0, size-1);
    auto t2 = Clock::now();
    std::cout << "Delta t2-t1: " 
       << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() 
       << " nanoseconds" << std::endl;
}


//Radix sort
// A utility function to get maximum value in arr[] 
int getMax(int arr[], int size) 
{ 
    int max = arr[0]; 
    for (int i = 1; i < size; i++) 
        if (arr[i] > max) 
            max = arr[i]; 
    return max; 
} 
  
void CountingSort(int arr[], int size, int div) 
{ 
    int output[size]; 
    int count[10] = {0}; 
  
    for (int i = 0; i < size; i++) 
        count[ (arr[i]/div)%10 ]++; 
  
    for (int i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    for (int i = size - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/div)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/div)%10 ]--; 
    } 
  
    for (int i = 0; i < size; i++) 
        arr[i] = output[i]; 
} 
  
 
void radixSort(int arr[], int size) 
{ 
    int m = getMax(arr, size); 
    for (int div = 1; m/div > 0; div *= 10) 
        CountingSort(arr, size, div); 
} 
   
void TheArrays::RadixSort(int arr[], int size)
{
    int temparray[size];
    copy(arr, arr + size, temparray);
    auto t1 = Clock::now();
	radixSort(temparray, size);  
    auto t2 = Clock::now();
    std::cout << "Delta t2-t1: " 
       << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() 
       << " nanoseconds" << std::endl;
}

void TheArrays::SortAll(int x)
{
    
    for (int i = 0; i < x; i++)
    {
        BubbleSort(small, 10);
        BubbleSort(schmedium, 100);
        BubbleSort(medium, 500);
        BubbleSort(large, 5000);
        BubbleSort(magnumxl, 25000);
        cout << "BubbleSort Test " << i << " " << endl;
        InsertionSort(small, 10);
        InsertionSort(schmedium, 100);
        InsertionSort(medium, 500);
        InsertionSort(large, 5000);
        InsertionSort(magnumxl, 25000);
        cout << "InsertionSort Test "<< i << " " << endl;
        MergeSort(small, 10);
        MergeSort(schmedium, 100);
        MergeSort(medium, 500);
        MergeSort(large, 5000);
        MergeSort(magnumxl, 25000);
        cout << "MergeSort Test "<< i << " " << endl;
        QuickSort(small, 10);
        QuickSort(schmedium, 100);
        QuickSort(medium, 500);
        QuickSort(large, 5000);
        QuickSort(magnumxl, 25000);
        cout << "QuickSort Test " << i << " " << endl;
        RadixSort(small, 10);
        RadixSort(schmedium, 100);
        RadixSort(medium, 500);
        RadixSort(large, 5000);
        RadixSort(magnumxl, 25000);
        cout << "RadixSort Test "<< i << " " << endl;
        if (i == x - 1)
        {
            RandomizeAll();
            cout << "Test Group " << i << "Complete " << endl;
        }
    }
}


