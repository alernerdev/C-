#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;			// right justified column width
using std::setprecision;	// at most floating point precision
using std::fixed;			// display floating numbers as fixed even if there is no floating point portion

#include <cmath>			// the old math.h header file where old C math functions are wrapped in std namespace
using std::pow;

int main()
{
	double amount;
	double principal = 1000.0;
	double rate = 0.05;

	// headers
	// setw is a NON sticky manipulator -- it applies just once to the very next argument
	cout << "Year" << setw(21) << "Amount of deposit" << endl;

	// data
	// these are sticky -- once set, they are set
	cout << fixed << setprecision(2);

	for (int year = 1; year <= 10; year++)
	{
		amount = principal * pow(1.0 + rate, year);
		cout << setw(4) << year << setw(21) << amount << endl;
	}

	return 0;
}