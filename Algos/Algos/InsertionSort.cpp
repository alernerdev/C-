#include "stdafx.h"
#include "Utils.h"
#include "InsertionSort.h"

/* similar to bubble sort in characteristics even though its a single pass algorithm
worst case: O(n squared)
avg: O(n squared)
best case for data thats already sorted: O(n)

benefit: performed entirely in place.  No extra allocations neeeded -- space efficient
*/
	
void CInsertionSort::Sort(int arr[], int length)
{
	bool swapped = false;

	m_visitingCount = 0;
	m_swapCount = 0;

	for (int i = 1; i < length; i++) // for all elements
	{
		for (int j = i; j > 0; j--) // take the next element and compare to elements to the left
		{
			m_visitingCount++;

			if (arr[j] < arr[j - 1])
			{
				swapped = true;

				m_swapCount++;
				Utils::Swap(arr, j, j - 1);
			}

			if (!swapped)
				break;
		}

		swapped = false;
	}
}
