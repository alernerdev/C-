#include <algorithm>
#include <vector>
#include <cmath> // for abs below
#include <random> // for shuffling.   Shuffle is opposite of sorting -- random

#include "Employee.h"

using namespace std;

int main()
{
	vector<int> v{ 4,1,0,1,-2,3,7,-6,2,0,0,-9,9 };
	auto v2 = v;
	sort(begin(v2), end(v2));  // sorting uses < operator to perform sorting

	// since I am using > to sort, this will be sorted in the opposite direction
	sort(begin(v2), end(v2),
		[](int elem1, int elem2) {return elem1 > elem2; });

	// and this sorts by absolute value
	// so you provide the comparison, and the sorting algo itself is abstracted
	sort(begin(v2), end(v2),
		[](int elem1, int elem2) {return abs(elem1) > abs(elem2); });


	vector<Employee> staff{
		{"Kate", "Gregory", 1000},
		{"Obvious", "Artificial", 2000},
		{"Fake", "Name", 1000},
		{"Alan", "Turing", 2000},
		{"Grace", "Hopper", 2000},
		{"Anita", "Borg", 2000}
	};

	// cant use sort here since < operator does not exist for the Employee class
	//sort(begin(staff), end(staff));

	sort(begin(staff), end(staff),
		[](Employee elem1, Employee elem2) {return elem1.getSortingName() < elem2.getSortingName(); });

	// when doing a sort on another field after the first sort, what should happen  to the original sort
	// if there is a collision of values?  If there are multiple same salary values, should they preserve the original 
	// sorted order of names ?  There are no guarantees -- it may preserve the order, and it may not
	sort(begin(staff), end(staff),
		[](Employee elem1, Employee elem2) {return elem1.getSalary() < elem2.getSalary(); });

	sort(begin(staff), end(staff),
		[](Employee elem1, Employee elem2) {return elem1.getSortingName() < elem2.getSortingName(); });
	// stable sort is slower, but it leaves salary collisions alone so the sorted names stay intact
	stable_sort(begin(staff), end(staff),
		[](Employee elem1, Employee elem2) {return elem1.getSalary() < elem2.getSalary(); });


	// is_sorted -- goes through collection and as soon as something is out of order, returns false.
	auto sorted = is_sorted(begin(v), end(v));

	// upper_bound -- finds next element thats greater than
	// lower_bound -- finds next element thats NOT less than?  -- works for SORTED collections only

	// max_element, min_element -- visits every element.  This is for unsorted collections
	int high = *(max_element(begin(v), end(v)));
	int low = *(min_element(begin(v), end(v)));
	// for a sorted collection, simply take the first and the last elements as low and high
	sort(begin(v2), end(v2));
	low = *begin(v2); high = *(end(v2) - 1);

	// get the next higher number than passed in 0
	int positive = *upper_bound(begin(v2), end(v2), 0);

	// this finds the element itself since lower_bound gives you not less than than the element
	sort(begin(staff), end(staff),
		[](Employee elem1, Employee elem2) {return elem1.getSortingName() < elem2.getSortingName(); });
	auto p = lower_bound(begin(staff), end(staff), "Gregory, Kate",
		[](Employee e1, string n) {return e1.getSortingName() < n; });
	int salary = p->getSalary();

	//-----------------------------------
	random_device randomdevice;
	mt19937 generator(randomdevice());
	shuffle(begin(v2), end(v2), generator);

	// partial_sort -- for large collections where you only need to sort a portion -- such as in pagination.
	// you are guaranteed that whatever was not sorted is still greater than what was sorted
	// partial_sort
	// is_sorted_until
	// partial_sort_copy
	return 0;
}