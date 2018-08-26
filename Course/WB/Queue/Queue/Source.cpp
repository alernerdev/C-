/*	
	WORRY i : пометить i - го человека с начала очереди(в нумерации с 0) как беспокоящегося;
	QUIET i : пометить i - го человека как успокоившегося;
	COME k : добавить k спокойных человек в конец очереди;
	COME - k: убрать k человек из конца очереди;
	WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main()
{
	int nops;
	cin >> nops;

	vector<int> v;

	string op;
	int count;

	for (int i = 0; i < nops; i++)
	{
		cin >> op;
		if (op == "WORRY")
		{
			cin >> count;
			v[count] = 1;
		}
		else if (op == "QUIET")
		{
			cin >> count;
			v[count] = 0;
		}		
		else if (op == "COME")
		{
			cin >> count;
			if (count > 0)
			{
				for (int j = 0; j < count; j++)
					v.push_back(0);
			}
			else
			{
				count *= -1;
				for (int j = 0; j < count; j++)
					v.pop_back();
			}
		}
		else if (op == "WORRY_COUNT")
		{
			int worried = 0;
			for (int j = 0; j < v.size(); j++)
			{
				if (v[j] == 1)
					worried++;
			}
			cout << worried << endl;
		}
	}
}