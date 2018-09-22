#include "pch.h"
#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"


/* reference in the base class is initialized with a concrete object from the derived class.
Specialized builders will be deriving from this base class -- thus, they all share a reference.  
There is only 1 Person object that gets instantiated
*/
PersonBuilderBase::PersonBuilderBase(Person & person) : m_person(person)
{
}

PersonAddressBuilder PersonBuilderBase::lives() const
{
	return PersonAddressBuilder{ m_person };
}

PersonJobBuilder PersonBuilderBase::works() const
{
	return PersonJobBuilder{m_person};
}


PersonBuilder::PersonBuilder() : PersonBuilderBase(m_p) 
{
}
