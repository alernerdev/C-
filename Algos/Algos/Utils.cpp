#include "stdafx.h"
#include <iostream>

#include "Utils.h"


void Utils::Swap(int arr[], int i1, int i2)
{
	int temp = arr[i1];
	arr[i1] = arr[i2];
	arr[i2] = temp;
}

void Utils::PrintArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
