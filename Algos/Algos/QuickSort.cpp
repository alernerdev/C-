#include "stdafx.h"
#include "Utils.h"
#include "QuickSort.h"


/* divide and conquer algorithm

worst case: can be as bad as O(n squared)
avg: O(n log n )
best case: O(n log n)

space: its O(n)
*/
CQuickSort::CQuickSort()
{
}


CQuickSort::~CQuickSort()
{
}

void CQuickSort::Sort(int arr[], int length)
{
	m_visitingCount=0;
	m_swapCount = 0;

	doSort(arr, 0, length - 1);
}

void CQuickSort::doSort(int arr[], int lowerIndex, int upperIndex)
{
	int i = lowerIndex;
	int j = upperIndex;
	int pivotIndex = i + (j - i) / 2;
	int pivot = arr[pivotIndex];

	while (i < j)
	{
		while (arr[i] < pivot)
		{
			m_visitingCount++;
			i++;
		}

		while (arr[j] > pivot)
		{
			m_visitingCount++;
			j--;
		}

		if (i <= j)
		{
			Utils::Swap(arr, i, j);
			i++;
			j--;
			m_visitingCount++;
			m_swapCount++;
		}
	}

	if (lowerIndex < j)
		doSort(arr, lowerIndex, j);

	if (i < upperIndex)
		doSort(arr, i, upperIndex);
}
