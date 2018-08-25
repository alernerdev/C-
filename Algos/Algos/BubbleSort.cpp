#include "stdafx.h"
#include "BubbleSort.h"
#include "Utils.h"

/*
	worst case: O(n squared)
	avg: O(n squared)
	best case for data thats already sorted: O(n)

	benefit: performed entirely in place.  No extra allocations neeeded -- space efficient
*/

void CBubbleSort::Sort(int arr[], int length)
{
	bool swapped = false;

	m_visitingCount = 0;
	m_swapCount = 0;

	for (int j = length - 1; j >= 0; j--) // and this is how many times
	{
		for (int i = 0; i < length - 1; i++) // for the entire array duration
		{
			m_visitingCount++;

			if (arr[i] > arr[i + 1])
			{
				Utils::Swap(arr, i, i + 1);
				m_swapCount++;
				swapped = true;
			}
		}

		// if nothing got swapped, break out of the loop -- done.
		if (!swapped)
			break;

		swapped = false;
	}
}


