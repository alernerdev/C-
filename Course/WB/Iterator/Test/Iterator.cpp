#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string s;

	cout << "please enter string\n";
	cin >> s;
	for (auto c : s)
	{
		cout << c << ',';
	}
	cout << "\n";

	vector<int> v = { 5,-4,6,-12,6 };
	for (auto i : v)
		cout << i << ",";

	cout << "\n";

	sort(begin(v), end(v));
	for (auto i : v)
		cout << i << ",";

	cout << "\n";

	int numof6 = count(begin(v), end(v), 6);

	char c;
	cin >> c;
	return 0;

}