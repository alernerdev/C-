#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>

void customType();

int main()
{
	cout << "sizeof int " << sizeof(int) << '\n';
	cout << "sizeof long " << sizeof(long) << '\n';

	vector<int> v = { 1, 2, 3, 4 };
	cout << "sizeof vector " << sizeof(vector<int>) << '\n';

	string s = "hello there";
	cout << "sizeof string " << sizeof(string) << '\n';

	cout << "sizeof float " << sizeof(float) << '\n';
	cout << "sizeof double " << sizeof(double) << '\n';
	cout << "sizeof bool " << sizeof(bool) << '\n';

	map<string, int> name_to_value;
	name_to_value["one"] = 1;
	name_to_value["two"] = 2;

	customType();
}

void customType()
{
	struct Person
	{
		string firstName;
		string lastName;
		int age;
	};

	vector<Person> staff;
	staff.push_back({ "alex", "lerner", 55 });
	staff.push_back({ "lydia", "smith", 65 });
	cout << staff[0].firstName << staff[0].lastName << '\n';
}