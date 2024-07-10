/*
 * ShopDb.cpp
 *
 *  Created on: 10.02.2024
 *      Author: mnl
 */

#include "ShopDb.h"
#include "Shop.h"

using namespace std;

ShopDb& ShopDb::addShop(std::unique_ptr<Shop>&& shop) {

	this->knownShops.insert(std::make_pair(shop->getName(), move(shop)));


	return *this;
}

vector<Shop*> ShopDb::shops() const {

	vector<Shop*> shopDb;
	for(auto& s: knownShops){
		shopDb.push_back(s.second.get());
	}
	return shopDb;
}

Shop* ShopDb::shopByName(std::string name) {
	vector<Shop*> nshopDb = shops();

	for(auto& shops: nshopDb){
		if(shops->getName() == name){
			return shops;
		}
	}
	return nullptr;
}


