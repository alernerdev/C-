#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	int count = 0;
	int index = -1;

	cin >> str;
	for (int i=0; i<str.size(); i++)
	{
		if (str[i] == 'f') {
			count++;
			if (count == 2) {
				index = i;
				break;
			}
		}
	}

	if (count == 0)
		cout << -2;
	else if (count == 1)
		cout << -1;
	else
		cout << index;

	return 0;
}