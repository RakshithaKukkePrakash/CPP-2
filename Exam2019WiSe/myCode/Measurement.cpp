/*
 * Measurement.cpp
 *
 *  Created on: 20-Jun-2024
 *      Author: acer
 */

#include "Measurement.h"
using namespace std;

Measurement::Measurement(uint16_t timestamp):timestamp(timestamp)
{
}

uint16_t Measurement::toTimestamp(int hour, int minute)
{

	if((hour <0 || hour > 23 ) && (minute <0 || minute > 59))
	{
		 throw std::invalid_argument("Invalid range");
	}
	return (hour*60 + minute);
}

std::string Measurement::toTimeOfDay(uint16_t timestamp)
{
	string newHr, newMin;
	int hour, minute;
	hour = timestamp/60;
	minute = timestamp % 60;
	if(hour<10)
	{
		newHr = '0'+ std::to_string(hour);
	}
	else
	{
		newHr = to_string(hour);
	}

	if(minute<10)
	{
		newMin = '0'+ to_string(minute);
	}
	else
	{
		newMin = to_string(minute);
	}

	return (newHr + ":" + newMin);
}

long Measurement::getTimestamp() const
{
	return timestamp;
}

std::ostream& operator <<(std::ostream &lhs, Measurement &rhs)
{
	lhs<<rhs.toTimeOfDay(rhs.getTimestamp()) <<" "<<rhs.toString();
	return lhs;
}

void Measurement::parseLine(const std::string &line, uint16_t &timestamp,
		std::string &type, std::string &remainder)
{
	auto pos1 = line.find(";");
	if(pos1 != std::string::npos)
	{
		timestamp = std::atol(line.substr(0,pos1).c_str());
	}
	int pos2 = line.find(":");
	type = line.substr(pos1+1, pos2);
	remainder = line.substr(pos2+1, std::string::npos);
}


Measurement::~Measurement()
{
}
