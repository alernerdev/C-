#pragma once

#include "Sort.h"

class CInsertionSort : public CSort
{
public:
	CInsertionSort() {}
	~CInsertionSort() {}

	void Sort(int arr[], int length);
};

