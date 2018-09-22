#pragma once
#include "PersonBuilder.h"

class PersonJobBuilder : public PersonBuilderBase
{
	typedef PersonJobBuilder self;

public:
	PersonJobBuilder(Person & person) : PersonBuilderBase(person) 
	{
	}

	self & at(string companyName)
	{
		m_person.companyName = companyName;
		return *this;
	}
	self & as_a(string position)
	{
		m_person.position = position;
		return *this;
	}
	self & earning(int annualIncome)
	{
		m_person.annualIncome = annualIncome;
		return *this;
	}
};

