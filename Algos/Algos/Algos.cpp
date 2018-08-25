// Algos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "Utils.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

#include "BTree.h"

int * GetData(int *numElems);
int QuickSort(int arr[], int lowerIndex, int upperIndex);
void DoBubbleSort();
void DoInsertSort();
void DoQuickSort();
void DoMergeSort();

int main()
{
	DoBubbleSort();
	DoInsertSort();
	DoMergeSort();
	DoQuickSort();

	std::cout << "Hit any key to continue" << std::endl;
	char ch;
	std::cin >> ch;

    return 0;
}

void BuildTree()
{
	BTree btree;
	btree.Insert(5);
	btree.Insert(6);
	btree.Insert(-1);
	btree.Insert(7);
	btree.Insert(-2);
	btree.Print();
}

void DoQuickSort()
{
	CQuickSort q;
	int length = 0;
	int * arr = GetData(&length);

	std::cout << "Quicksort\n";
	Utils::PrintArray(arr, length);
	q.Sort(arr, length);

	int numVisits, numSwaps;
	q.GetStats(&numVisits, &numSwaps);

	std::cout <<
		"Num of Elements " << length <<
		" Num of iterations " << numVisits <<
		" Num of swaps " << numSwaps <<
		std::endl;

	Utils::PrintArray(arr, length);

	delete[]arr;
}

void DoBubbleSort()
{
	CBubbleSort bubble;
	int length = 0;
	int * arr = GetData(&length);

	std::cout << "Bubblesort\n";
	Utils::PrintArray(arr, length);

	bubble.Sort(arr, length);
	int numVisits, numSwaps;
	bubble.GetStats(&numVisits, &numSwaps);
	Utils::PrintArray(arr, length);

	std::cout << 
		"Num of Elements " << length << 
		" Num of iterations " << numVisits << 
		" Num of swaps " << numSwaps <<
		std::endl;

	delete[]arr;
}

void DoInsertSort()
{
	CInsertionSort ins;
	int length = 0;
	int * arr = GetData(&length);

	std::cout << "Insertion sort\n";
	Utils::PrintArray(arr, length);

	ins.Sort(arr, length);
	int numVisits, numSwaps;
	ins.GetStats(&numVisits, &numSwaps);
	Utils::PrintArray(arr, length);

	std::cout <<
		"Num of Elements " << length <<
		" Num of iterations " << numVisits <<
		" Num of swaps " << numSwaps <<
		std::endl;

	delete[]arr;
}

void DoMergeSort()
{
	CMergeSort merge;
	int length = 0;
	int * arr = GetData(&length);

	std::cout << "Merge sort\n";
	Utils::PrintArray(arr, length);

	merge.Sort(arr, length);
	int numVisits, numSwaps;
	merge.GetStats(&numVisits, &numSwaps);
	Utils::PrintArray(arr, length);

	std::cout <<
		"Num of Elements " << length <<
		" Num of iterations " << numVisits <<
		" Num of swaps " << numSwaps <<
		std::endl;

	delete[]arr;
}

int * GetData(int *numElems)
{
	int arr[] = {100, 3, 2, 1, 4, 5, 6, 7, 10, 9, 8}; // original array
	*numElems = sizeof(arr) / sizeof(int);

	int * newArr = new int[*numElems];
	memmove(newArr, arr, sizeof(arr));
	return newArr;
}


