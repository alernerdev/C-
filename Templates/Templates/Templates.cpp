// Templates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

typedef pair<int, int> int_pair;
typedef tuple<int, int, int> int_triple;

int_pair SumAndProduct(int a, int b)
{
	return int_pair(a + b, a*b);
}

int_triple SumProductAverage(int a, int b, int c)
{
	int_triple t { a + b + c, a*b*c, (a + b + c) / 3 };
	return t;
}

// templated class
template <typename T1, typename T2, typename T3>
struct triple
{
	typedef T1 resultType;

	T1 first;
	T2 second;
	T3 third;

	triple(const T1& f, const T2& s, const T3& t) :
		first(f), second(s), third(t)
	{

	}
};
typedef triple<int, int, int> myNewTriple;

myNewTriple SumProductAverage2(int a, int b, int c)
{
	myNewTriple t{ a + b + c, a*b*c, (a + b + c) / 3 };
	return t;
}

// templated function
template <typename T1, typename T2, typename T3>
triple<T1, T2, T3> doMath(const T1& t1, const T2& t2, const T3& t3)
{
	// had to jump through hoops for the division by 3 because if the arguments are complex numbers,
	// cant divide by integer 3-- it had to be a complex number *
	return triple<T1, T2, T3>(t1 + t2 + t3, t1 * t2 * t3, (t1 + t2 + t3) / triple<T1, T2, T3>::resultType(3));
}

void consumingTemplates()
{
	int a = 3, b = 4, c=5;

	auto pairRes = SumAndProduct(a, b);
	cout << "elements " << a << " and " << b <<
		" Sum=" << pairRes.first << 
		" Product=" << pairRes.second << endl;

	auto tripleRes = SumProductAverage(a, b, c);
	cout << "elements " << a << " " << b << " " << c <<
		" Sum=" << get<0>(tripleRes) <<
		" Product=" << get<1>(tripleRes) <<
		" Avg=" << get<2>(tripleRes) <<	endl;

	auto triple = SumProductAverage2(a, b, c);
	cout << "elements " << a << " " << b << " " << c <<
		" Sum=" << triple.first <<
		" Product=" << triple.second <<
		" Avg=" << triple.third << endl;
}

void templateFunctions()
{
	int a = 5;
	double b = 3.4;
	float c = 3.5f;

	auto res = doMath(a, b, c);
	cout << "elements " << a << " " << b << " " << c <<
		" Sum=" << res.first <<
		" Product=" << res.second <<
		" Avg=" << res.third << endl;

}

typedef complex<double> cd;
typedef triple<cd, cd, cd> cdt;

// specialization
template <> cdt doMath(const cd& t1, const cd& t2, const cd& t3)
{
	// in this specialization for complex numbers, I am only doing math on the REAL portion of the compex numbers
	auto result = doMath(t1.real(), t2.real(), t3.real());
	return cdt(result.first, result.second, result.third);
}
void templateSpecialization()
{
	cd a(3, 4), b(2, 3), c(5.6);
	auto res = doMath(a, b, c);
	cout << "elements " << a << " " << b << " " << c <<
		" Sum=" << res.first <<
		" Product=" << res.second <<
		" Avg=" << res.third << endl;

}

int main()
{
	//consumingTemplates();
	//templateFunctions();
	templateSpecialization();

	getchar();
    return 0;
}

