#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void Print(const vector<string> & vec)
{
	for (auto v : vec)
		cout << v << " ";
}

string tolower(const string & s)
{
	string lower = s;
	for (auto & c : lower)
		c = tolower(c);

	return lower;
}

int main()
{
	int N;
	cin >> N;

	vector<string> strings;
	string s;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		strings.push_back(s);
	}

	sort(begin(strings), end(strings), [](const string & a, const string & b) {
		return tolower(a) < tolower(b);
	});

	Print(strings);
	cout << endl;
}