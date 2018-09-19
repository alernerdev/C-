#include <iostream>
#include <string>
#include <exception>
using namespace std;

class MyException : public exception
{
public:
	virtual const char * what()
	{
		return "Something bad from my Exception class";
	}
};

class Test
{
public:
	void goesWrong()
	{
		throw MyException();
	}
};


int main()
{
	try
	{
		Test wrong;
		wrong.goesWrong();
	}
	catch (MyException & e)
	{
		cout << e.what() << "\n";
	}

	return 0;
}