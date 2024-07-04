/*
 * Item.cpp
 *
 *  Created on: 21-Jun-2024
 *      Author: acer
 */

#include "Item.h"
using namespace std;
Item::Item(std::string name, std::string shop, std::time_t until):name(name),
shop(shop), until(until)
{
}

Item::~Item()
{
}

std::string Item::getName() const
{
	return this->name;
}

std::string Item::getShop() const
{
	return this->shop;
}

std::time_t Item::getUntil() const
{
	return this->until;
}

std::string Item::toString() const
{
	return (this->name + "[" + this->shop + "]");
}

void Item::save(std::ostream &to) const
{
	to << "Item;" <<getName() <<";" <<getShop() <<";" <<getUntil()<<";" << endl;
}

Item* Item::restore(std::string line)
{

	extern string splitAt(string& remainder, char separator);

	string label = splitAt(line, ';');

	name  = splitAt(line, ';');
	shop = splitAt(line, ';');
	until = std::stod(splitAt(line, '\n'));
	if(label != "Item")
	{
		return nullptr;
	}

	return this;
}

std::ostream& operator <<(std::ostream &lhs, const Item &item)
{
	lhs << item.getName()<<";" << item.getShop()<<";" << item.getUntil();
	return lhs;
}

std::set<std::string> Item::getNotes() const
{
	set<string> data;
	return data;
}
