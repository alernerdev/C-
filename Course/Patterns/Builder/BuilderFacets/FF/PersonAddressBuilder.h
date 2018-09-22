#pragma once
#include "PersonBuilder.h"
class PersonAddressBuilder : public PersonBuilderBase
{
	typedef PersonAddressBuilder self;

public:
	PersonAddressBuilder(Person & person) : PersonBuilderBase(person)
	{
	}

	self & at(string streetAddress)
	{
		m_person.streetAddress = streetAddress;
		return *this;
	}
	self & withPostCode(string postCode)
	{
		m_person.postCode = postCode;
		return *this;
	}
	self & in(string city)
	{
		m_person.city = city;
		return *this;
	}
};

