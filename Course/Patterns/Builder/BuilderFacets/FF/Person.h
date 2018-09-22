#pragma once

class PersonBuilder;

class Person
{
protected:
	// address
	string streetAddress, postCode, city;

	// employment
	string companyName, position;
	int annualIncome{ 0 };

public:
	static PersonBuilder create();

	friend ostream & operator<<(ostream & os, const Person & person)
	{
		return os
			<< "streetAddress: " << person.streetAddress
			<< "postCode: " << person.postCode
			<< " city: " << person.city
			<< " company_name: " << person.companyName
			<< " position: " << person.position
			<< " annual_income: " << person.annualIncome;
	}

	friend class PersonBuilder;
	friend class PersonJobBuilder;
	friend class PersonAddressBuilder;
};

