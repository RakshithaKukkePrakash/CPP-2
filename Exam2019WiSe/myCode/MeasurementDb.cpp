/*
 * MeasurementDb.cpp
 *
 *  Created on: 20-Jun-2024
 *      Author: acer
 */

#include "MeasurementDb.h"
using namespace std;
MeasurementDb::MeasurementDb()
{

}

void MeasurementDb::addMeasurement(const std::string &location,
		std::shared_ptr<Measurement> measurement)
{
	data[location].push_back(measurement);
}

void MeasurementDb::print()
{
	cout<<"Content of database: "<<endl;
	for(auto& content: this->data)
	{
		for(auto& con2: content.second)
		{
			cout<< content.first << ": "<< *con2<<endl;
		}

	}
}

void MeasurementDb::save(std::ostream &to)
{
	for(auto& content: this->data)
	{
		to << '[' << content.first << ']'<<endl;
		for(auto& con2: content.second)
		{
			to << con2->getTimestamp() <<";"<<con2->toString()<<endl;
		}
	}

}

void MeasurementDb::load(std::istream &from)
{
	this->data.clear();
	std::string line, location, type, remainder ;
	uint16_t timestamp;
	while(getline(from, line))
	{
		auto pos1 = line.find("]");
		location = line.substr(1, pos1-1);
		auto pos2 = line.find(";");
		timestamp = std::atol(line.substr(1, pos1-1).c_str());
	}
}

MeasurementDb::~MeasurementDb()
{
}

