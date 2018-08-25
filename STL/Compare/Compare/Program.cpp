#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int main()
{
	vector<int> a{ 1,2,3,4,5 };
	vector<int> b{ 1,2,0,4,5 };

	bool same = equal(begin(a), end(a), begin(b), end(b));

	// bug or a feature, but mismatch only works on the same length collections
	auto firstchange = mismatch(begin(a), end(a), begin(b));
	// firstchange returned is a pair
	int avalue = *(firstchange.first);
	int bvalue = *(firstchange.second);

	return 0;
}