#include <iostream>

using namespace std;

int main()
{
	int in1, in2;
	int largestDiv = 1;

	cin >> in1 >> in2;

	// if same numbers, they are their own divider
	if (in1 == in2)
	{
		cout << in1;
		return 0;
	}

	/*
	I imagine this brute force approach also works but coursera  runs out of time

	int smallest = in1 < in2 ? in1 : in2;
	for (int i = 2; i <= smallest; i++)
	{
		if ((in1 % i == 0) && (in2 % i == 0)) 
		{
			largestDiv = i;
		}
	}
	cout << largestDiv;
	*/

	while (in1 > 0 && in2 > 0)
	{
		if (in1 > in2)
			in1 = in1%in2;
		else
			in2 = in2 % in1;

	}
	cout << in1 + in2;

	return 0;
}