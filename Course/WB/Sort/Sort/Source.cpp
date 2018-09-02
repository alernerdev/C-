#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Print(const vector<int> & vec)
{
	for (auto v : vec)
		cout << v << " ";
}

int main()
{
	int N;
	cin >> N;

	vector<int> numbers;
	int number;
	for (int i = 0; i < N; i++)
	{
		cin >> number;
		numbers.push_back(number);
	}

	sort(begin(numbers), end(numbers), [](int a, int b) {
		return abs(a) < abs(b);
	});
	Print(numbers);
	cout << endl;
}