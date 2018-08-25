#include <iostream>
#include <vector>

using namespace std;

int dec2bin(int number);

int main()
{
	int num;
	cin >> num;

	if (num == 0) {
		cout << 0;
		return 0;
	}

	vector<int> v;
	int remainder;	
	while (num > 0) {
		remainder = num % 2;
		num = num / 2;
		v.push_back(remainder);
	}

	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i];
	}
}

int dec2bin(int number)
{
	int bin = 0;
	int i = 1;


	while (number > 0) {
		bin += (number % 2) * i;
		number = number / 2;
		i *= 10;
	}

	return bin;
}