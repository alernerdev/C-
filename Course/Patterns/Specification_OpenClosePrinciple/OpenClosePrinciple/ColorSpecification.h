#pragma once

#include "Product.h"
#include "Specification.h"

struct ColorSpecification : Specification<Product>
{
protected:
	Color color;

public:
	ColorSpecification(Color color) : color(color) {}

	bool isSatisfied(Product *item) const override {
		return item->color == color;
	}
};
