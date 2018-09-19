#include "stdafx.h"

namespace life
{
	int meaning = 42;
}

auto add(int a, int b) 
{ 
	return a + b; 
}

auto add2(int a, int b) -> int {return a + b;}

int main()
{
	cout << "Hello, world" << endl;
	cout << life::meaning << endl;

	auto sum = add(5, 6);

	auto doublevalue = [](int z) {return z * 2; };

	cout << " my double value " << doublevalue(5) << endl;
	int y = 5;
	auto increaseByY = [y](int z) {return z + y; };
	cout << "increase by y " << 
		increaseByY(6) << endl;

	getchar();

    return 0;
}

