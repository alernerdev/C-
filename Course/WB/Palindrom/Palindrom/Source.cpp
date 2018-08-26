#include <iostream>
#include <string>
#include <vector>
using namespace std;

extern vector<string> PalindromFilter(vector<string>, int);

int  main()
{
	vector<string> v = { "abacaba", "aba", "a", "ab" };
	vector<string> res = PalindromFilter(v, 2);
	for (auto w : res)
	{
		cout << w << endl;
	}
}
