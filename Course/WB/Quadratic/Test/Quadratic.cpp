#include <cmath>

#include <iostream>

using namespace std;

int main() {
	float x1, x2;
	float a, b, c;

	cin >> a >> b >> c;

	if (a == 0)
	{
		if (b == 0)
		{
			// if a and b is 0, this is invalid input
		}
		else 
			cout << (c * -1) / b;
	}
	else if (b == 0)
	{
		if (c == 0)
		{
			cout << 0;
		}
		else
		{
			float t = sqrt(-1 * c / a);
			if (t >= 0)
			{
				x1 = sqrt(t);
				x2 = -1 * sqrt(t);
				cout << x1;
				if (x1 != x2) {
					cout << " " << x2;
				}
			}
		}
	}
	else
	{
		float t = b * b - 4 * a*c;
		if (t >= 0)
		{
			x1 = (-1 * b + sqrt(t)) / (2 * a);
			x2 = (-1 * b - sqrt(t)) / (2 * a);
			cout << x1;
			if (x1 != x2) {
				cout << " " << x2;
			}
		}
	}

	return 0;

}