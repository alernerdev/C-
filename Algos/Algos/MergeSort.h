#pragma once
#include "Sort.h"
class CMergeSort : public CSort
{
public:
	CMergeSort();
	~CMergeSort() {};

	void Sort(int arr[], int length);

protected:
	void doMergeSort(int lowerIndex, int higherIndex);
	void mergeParts(int lowerIndex, int middle, int higherIndex);

	int *m_arr;
	int *m_sortedArr;
	int m_length;
};

