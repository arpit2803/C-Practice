#include"stdafx.h"
#include<iostream>
#include<conio.h>

void printArray(int* arr, int length);
void Sort(int* arr, int low, int length);
using namespace std;
int QuickSort()
{
	int arr[] = { 89, 34, 100, 29, 88, 12, 23, 98, 93, 78 };
	//int arr[] = { 0, 1, 0, 1, 1, 1, 1, 0, 0,0};
	int length = 0;
	length = sizeof(arr) / sizeof(arr[0]);
	cout <<'\n' << "Array before soritng:";
	printArray(arr, length);
	cout << '\n' << "Array after sorting:" << '\n';
	Sort(arr, 0, length - 1);
	return arr[0];
}

void Sort(int* arr, int low, int length)
{
	if (low < length)
	{
		int pivot = arr[length];
		int itr1 = low - 1;
		int itr2 = low;
		//while (itr2 <= length)
		for (int i = low; i <= length; i++)
		{
			//itr2++;
			if (arr[itr2] <= pivot)
			{
				itr2++;
			}
			else
			{

				itr1++;
				int temp = arr[itr2];
				arr[itr2] = arr[itr1];
				arr[itr1] = temp;
				itr2++;
			}
		}
		itr1++;
		int temp = arr[itr1];
		arr[itr1] = arr[length];
		arr[length] = temp;
		printArray(arr, 9);
		Sort(arr, low, itr1 - 1);
		Sort(arr, itr1 + 1, length);
		printArray(arr, 9);
	}
}

void printArray(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] <<" ";
	}
	system("pause");
}