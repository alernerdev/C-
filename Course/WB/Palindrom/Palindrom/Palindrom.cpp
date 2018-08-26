#include <string>
#include <vector>
using namespace std;

bool IsPalindrom(string s);

vector<string> PalindromFilter(vector<string> words, int minLength)
{
	vector<string> results;

	for (auto word : words) {
		if (word.size() < minLength)
			continue;

		if (!IsPalindrom(word))
			continue;

		results.push_back(word);
	}

	return results;
}


bool IsPalindrom(string s)
{
	if (s.size() == 0 || s.size() == 1)
	{
		return true;
	}

	for (int i = 0; i < s.size() / 2; i++)
	{
		if (s[i] != s[s.size() - i - 1])
			return false;
	}

	return true;
}