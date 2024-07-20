/*
 * QuantityDiscount.cpp
 *
 *  Created on: 11.02.2024
 *      Author: mnl
 */

#include "QuantityDiscount.h"
using namespace std;
QuantityDiscount& QuantityDiscount::addLimit(float quantity, float discount) {
	this->limits.emplace(std::make_pair(quantity, discount));
	return *this;

}

float QuantityDiscount::discountFor(float quantity) const {
	for(auto& lim : limits)
	{
		if(quantity >= lim.first)
		{
			return lim.second;
		}
	}
	return 0;
}

