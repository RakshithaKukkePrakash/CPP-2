/*
 * Address.h
 *
 *  Created on: 01-Jul-2024
 *      Author: acer
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_
#include <iostream>
class Address
{
	std::string street;
	unsigned short postalCode;
	std::string cityName;
	std::string additionalInfo;
public:
	Address();
	virtual ~Address();
};

#endif /* ADDRESS_H_ */
