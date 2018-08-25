#pragma once

#include <string>
using namespace std;

class Employee
{
public:
	Employee(string first, string last, int sal) :
		firstname(first), lastname(last), salary(sal)
	{

	}
	int getSalary() { return salary; }
	string getSortingName() { return lastname + ", " + firstname; 
	}
	~Employee() {}

private:
	string firstname;
	string lastname;
	int salary;
};

