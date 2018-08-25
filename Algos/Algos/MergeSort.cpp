#include "stdafx.h"
#include "MergeSort.h"

/* divide and conquer algorithm -- same performance in all cases.  THis is because it
does the same thing no matter if data is already sorted.  Its a fixed predictable cost

worst case: O(n log n)
avg: O(n log n )
best case: O(n log n)

typically NOT done in place, but if it is, its O(n)
*/

CMergeSort::CMergeSort() :
	m_arr(nullptr), m_length(0), m_sortedArr(nullptr)
{
}

void CMergeSort::Sort(int arr[], int length)
{
	m_visitingCount = 0;
	m_swapCount = 0;

	m_arr = arr;
	m_length = length;
	m_sortedArr = new int[length];

	// start the recursion
	doMergeSort(0, length - 1);
}

void CMergeSort::doMergeSort(int lowerIndex, int higherIndex) 
{
	if (lowerIndex < higherIndex) 
	{
		int middle = lowerIndex + (higherIndex - lowerIndex) / 2;

		// Below step sorts the left side of the array
		doMergeSort(lowerIndex, middle);

		// Below step sorts the right side of the array
		doMergeSort(middle + 1, higherIndex);

		// Now merge both sides
		mergeParts(lowerIndex, middle, higherIndex);
	}
}

void CMergeSort::mergeParts(int lowerIndex, int middle, int higherIndex)
{
	for (int i = lowerIndex; i <= higherIndex; i++) {
		m_sortedArr[i] = m_arr[i];
	}

	int i = lowerIndex;
	int m = middle + 1;
	int k = lowerIndex;
	while (i <= middle && m <= higherIndex) 
	{
		if (m_sortedArr[i] <= m_sortedArr[m]) 
		{
			m_arr[k] = m_sortedArr[i];
			i++;
		}
		else 
		{
			m_arr[k] = m_sortedArr[m];
			m++;
		}
		k++;
	}
	while (i <= middle)
	{
		m_arr[k] = m_sortedArr[i];
		k++;
		i++;
	}
}
