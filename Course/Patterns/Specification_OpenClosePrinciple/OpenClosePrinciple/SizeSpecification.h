#pragma once

#include "Product.h"
#include "Specification.h"

struct SizeSpecification : Specification<Product>
{
protected:
	Size size;

public:
	SizeSpecification(Size size) : size(size) {}

	bool isSatisfied(Product *item) const override {
		return item->size == size;
	}
};

