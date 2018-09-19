#pragma once

#include "Specification.h"
#include "Product.h"

struct BetterFilter : Filter<Product>
{
	vector<Product *> filter(vector<Product*> items, Specification<Product> & spec) override
	{
		vector <Product *> result;
		for (const auto & item : items)
			if (spec.isSatisfied(item))
				result.push_back(item);

		return result;
	};
};

