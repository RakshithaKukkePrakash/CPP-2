/*
 * Shop.cpp
 *
 *  Created on: 10.02.2024
 *      Author: mnl
 */

#include <list>
#include <stdexcept>

#include "Shop.h"
#include "ShoppingList.h"
#include "Item.h"
#include "Discount.h"

using namespace std;

Shop::Shop(std::string name) : name(name) {
}

std::string Shop::getName() const {
	return name;
}

Shop& Shop::addProduct(const Product &product) {
	this->products.insert(std::make_pair(this->name, product));
	return *this;
}

Shop& Shop::setBasePrice(std::string productName, float basePrice) {
	for(auto& prod: this->products)
	{
		if(prod.first != productName){
			throw invalid_argument("Product not available at shop");
		}
		else{
			prod.second.setBasePrice(basePrice);
		}
	}
	return *this;
}

Shop& Shop::setDiscount(std::string productName,
		std::shared_ptr<Discount> discount) {

	for(auto& prod: this->products)
	{
		if(prod.first != productName){
			throw invalid_argument("Product not available at shop");
		}
		else{
			prod.second.setDiscount(discount);
		}
	}
	return *this;
}

float Shop::calculatePurchase(const ShoppingList& shoppingList,
		std::set<const Item*>& notAvailable) const {
	float finalPurchasePrice;
	std::list<Item>::const_iterator begin, end;
	shoppingList.items(begin, end);
	for(auto iterator = begin; iterator!= end ; iterator++)
	{
		for(auto& itm: notAvailable){
			if(itm->getName() != iterator->getName()){
				for(auto& prod: products){
					if(prod.first == iterator->getName())
					{
						finalPurchasePrice+= prod.second.priceFor(iterator->getQuantity());

					}
				}
			}
		}

	}

	return 0;
}

