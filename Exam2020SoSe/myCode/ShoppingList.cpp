/*
 * ShoppingList.cpp
 *
 *  Created on: 21-Jun-2024
 *      Author: acer
 */

#include <iostream>
#include "ShoppingList.h"
#include "Food.h"
using namespace std;


ShoppingList::ShoppingList()
{

}

ShoppingList& ShoppingList::operator +=(Item *item)
{
	items[item->getName()].emplace_back(std::make_unique<Item>(item));
	return *this;
}

void ShoppingList::print(std::time_t until) const
{
	 // Hint: use a set to collect all notes from the various items
	 // and print its content at the end.



}

void ShoppingList::save(std::ostream &to) const
{
}

void ShoppingList::load(std::istream &from)
{
}

ShoppingList::~ShoppingList()
{
	// TODO Auto-generated destructor stub
}

