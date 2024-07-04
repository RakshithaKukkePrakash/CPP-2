/*
 * Food.cpp
 *
 *  Created on: 21-Jun-2024
 *      Author: acer
 */

#include <string>
#include "Food.h"
using namespace std;



Food::Food(std::string name, std::string shop, std::time_t until,
		bool needsCooling):Item(name, shop, until), needsCooling(needsCooling)
{
}

bool Food::getNeedsCooling() const {
 return needsCooling;
}
set<string> Food::getNotes() const {
	 if (!needsCooling) {
		 return set<string>();
	 }
	 set<string> result;
	 result.insert("One or more items require cooling!");
	 return result;
}


std::string Food::toString() const
{
	if(needsCooling)
	{
		return (Item::toString() + " [Keep cool!]");
	}
	return Item::toString();
}

void Food::save(std::ostream &to) const
{
	to << Item::save(to)<<";" <<this->needsCooling<< endl;
}

Food* Food::restore(string line) {
	 extern string splitAt(string& remainder, char separator);
	 string name, shop;
	 std::time_t until;
	string label = splitAt(line, ';');
	name  = splitAt(line, ';');
	shop = splitAt(line, ';');
	until = std::stod(splitAt(line, ';'));
	Item(name, shop, until);
	if(label != "Food")
	{
		return nullptr;
	}
	return this;

}

Food::~Food()
{
}
