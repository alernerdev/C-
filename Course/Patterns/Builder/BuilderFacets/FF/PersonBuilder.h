#pragma once

#include "Person.h"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase
{
protected:
	Person & m_person;

public:
	PersonBuilderBase(Person & person);
	operator Person() const 
	{
		return move(m_person);
	}

	PersonAddressBuilder lives() const;
	PersonJobBuilder works() const;
};

class PersonBuilder : public PersonBuilderBase
{
private:
	Person m_p;

public:
	PersonBuilder();
};

