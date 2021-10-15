
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>

class TheArrays{
	public:
	TheArrays();
	void PrintEM();
    void BubbleSort(int arr[], int size);
    void InsertionSort(int arr[], int size);
    void MergeSort(int arr[], int size);
    void QuickSort(int arr[], int size);
    void RadixSort(int arr[], int size);
    void SortAll(int i);
    void RandomizeAll();

    private:
    int small[10];
    int schmedium[100];
    int medium[500];
    int large[5000];
    int magnumxl[25000];
};
