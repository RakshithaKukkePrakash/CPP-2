/*
 * MeasurementDb.h
 *
 *  Created on: 20-Jun-2024
 *      Author: acer
 */

#ifndef MEASUREMENTDB_H_
#define MEASUREMENTDB_H_
#include "Measurement.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <vector>
#include <memory>
#include <cstdint>
class MeasurementDb
{
	std::map<std::string, std::vector<std::shared_ptr<Measurement>>> data;
public:
	MeasurementDb();
	void addMeasurement(const std::string& location, std::shared_ptr<Measurement> measurement);
	void print();
	void save(std::ostream& to);
	void load(std::istream& from);
	virtual ~MeasurementDb();
};

#endif /* MEASUREMENTDB_H_ */
