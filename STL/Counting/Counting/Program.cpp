#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int CountValueDemo(vector<int> & v, int target);
int CountOddDemo(vector<int> & v);
int CountMapDemo(vector<int> & v);
void AllNoneAnyDemo(vector<int> &v);


int main()
{
	// SHOWS THE USAGE OF:
	//		count, count_if, begin(v)/end(v)
	//		all_of, any_of, none_of

	vector<int> v{ 2, -6, 5,200, 2, 2, 7 };

	// count how many entries have the target value 2
	int const target = 2;
	int count = CountValueDemo(v, target);

	// count how many entries are odd
	count = CountOddDemo(v);

	// count how many months are 31 days
	count = CountMapDemo(v);

	AllNoneAnyDemo(v);

	return 0;
}

void AllNoneAnyDemo(vector<int> &v)
{		
	bool all = all_of(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });
	bool none = none_of(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });
	bool any = any_of(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });
}

int CountMapDemo(vector<int> &v)
{
	// counts how many months are 31 days
	map<int, int> months  { {1,31}, {2,28}, {3,31}, {4, 30},{ 5, 31 },{ 6, 30 },{ 7, 31 },{ 8, 30 },{ 9, 31 },{ 10, 30 },{ 11, 30 },{ 12, 31 } };

	return count_if(begin(months), end(months),
		[](auto elem) {return elem.second == 31; });
}

int CountOddDemo(vector<int> & v)
{
	int odds = 0;

	// old way -- but check out this loop syntax -- for every element in v
	for (auto elem : v)
	{
		if (elem % 2 != 0)
			odds++;
	}

	// STL way
	odds = count_if(begin(v), end(v),
		[](auto elem) {return elem % 2 != 0; });

	return odds;
}

int CountValueDemo(vector<int> & v, int target) 
{
	int cnt = 0;

	// old way
	for (size_t i = 0; i < v.size(); i++)
		if (v[i] == target)
			cnt++;

	// alternatively, STL way
	// using member begin/end
	cnt = count(v.begin(), v.end(), target);

	// using non-member begin/end.  non-member also work on C style [] arrays
	// non-member begin/end uses member begin/end if it exists and this is the 
	// preferred way
	cnt = count(begin(v), end(v), target);

	return cnt;
}