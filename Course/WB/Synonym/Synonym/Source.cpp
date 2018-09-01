#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;
int main()
{
	int nops;
	cin >> nops;

	map<string, set<string>> wordToSyn;

	string op;
	for (int i = 0; i < nops; i++)
	{
		cin >> op;
		if (op == "ADD")
		{
			string word1, word2;
			cin >> word1;
			cin >> word2;

			set<string> & syn1 = wordToSyn[word1];
			syn1.insert(word2);

			set<string> & syn2 = wordToSyn[word2];
			syn2.insert(word1);
		}
		else if (op == "COUNT")
		{
			string word;
			cin >> word;

			const set<string> & synonyms = wordToSyn[word];
			cout << synonyms.size() << endl;

		}
		else if (op == "CHECK")
		{
			string word1, word2;
			cin >> word1;
			cin >> word2;

			const set<string> & synonyms1 = wordToSyn[word1];
			if (synonyms1.count(word2)) 
			{
				cout << "YES" << endl;
				continue;
			}

			// if still here
			const set<string> & synonyms2 = wordToSyn[word2];
			if (synonyms2.count(word1))
			{
				cout << "YES" << endl;
				continue;
			}

			cout << "NO" << endl;
		}
	}
}

