#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int weLookedFor;

	vector<int> v{ 5, 6, 2, 2, 2, 3, -199, 2,3, 17 };
	string s{ "Hello I am a sentence" };

	// find the first 2 in the collection
	auto result = find(begin(v), end(v), 2);
	if (result != end(v))
		weLookedFor = *result;
	else
		exit(-1); // didnt find it

	// another example where I continue searching from the previous result
	// this time, looking for -199
	result = find(result, end(v), -199);
	if (result != end(v))
		weLookedFor = *result;

	// finding chars in a string
	auto letter = find(begin(s), end(s), 'a');
	char a = *letter;
	
	// find first odd number
	result = find_if(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });
	int odd = *result;

	/* there is also:
		find_if_not
		find_first_of
		find_end
		search
		search_n
		adjacent_find
	*/
	// first even value -- uses the same odd lambda but find_if_not is used
	result = find_if_not(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });
	int even = *result;

	// finds the first element in v that is part of primes
	vector<int>primes{ 1,3,5,7,11,13 };
	result = find_first_of(begin(v), end(v), begin(primes), end(primes));
	weLookedFor = *result;

	//---------------
	vector<int> subsequence { 2,3 };
	result = search(begin(v), end(v), begin(subsequence), end(subsequence));
	weLookedFor = *result;
	// according to my fudged data, if I skip first 2,3 I should be looking at -199
	result++; result++;
	weLookedFor = *result; // is this -199 ?

	//----------------
	// this can find  strings within a string
	string ello = "ello";
	letter = search(begin(s), end(s), begin(ello), end(ello));
	a = *letter;

	//---------------
	// also looks for a sequence, but from the end
	result = find_end(begin(v), end(v), begin(subsequence), end(subsequence));
	weLookedFor = *result;
	// according to my fudged data, if I skip first 2,3 I should be looking at 17
	result++; 	result++;
	weLookedFor = *result; // is this 17 ?

	// looking for 3 sevens in a row
	// result = search_n(begin(v), end(v), 3, 7);

	// finds two the same adjacent values - you dont get to choose which ones
	// result = adjacent_find(begin(v), end(v));
	return 0;
}