#pragma once

#include "pch.h"

// specification pattern
template <typename T> struct Specification
{
	virtual bool isSatisfied(T *item) const = 0;
	virtual ~Specification() = default;
};

template <typename T> struct Filter
{
 	virtual vector<T*>filter(vector<T*> items, Specification<T> & spec ) = 0;
};

// combine several sepcifications
template <typename T> struct AndSpecification : Specification<T>
{
protected:
	Specification<T> & first;
	Specification<T> & second;

public:
	AndSpecification(Specification<T> & first, Specification<T> & second) : first(first), second(second){}
	bool isSatisfied(T* item) const override
	{
		return (first.isSatisfied(item) && second.isSatisfied(item));
	}
};


