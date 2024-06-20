/*
 * Humidity.h
 *
 *  Created on: 20-Jun-2024
 *      Author: acer
 */

#ifndef HUMIDITY_H_
#define HUMIDITY_H_
#include "Measurement.h"
#include <memory>
class Humidity: public Measurement
{
	float humidity;
public:
	Humidity(uint16_t timestamp, float humidity);
	float getHumidity() const;
	std::string toString() const;
	static std::shared_ptr<Humidity> fromString(uint16_t timestamp, std::string value);
	virtual ~Humidity();
};

#endif /* HUMIDITY_H_ */
