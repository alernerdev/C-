#pragma once
#include "Sort.h"
class CQuickSort : public CSort
{
public:
	CQuickSort();
	~CQuickSort();

	void Sort(int arr[], int length);

private:
	void doSort(int arr[], int lowerIndex, int upperIndex);
};

