/*
 * Temperature.cpp
 *
 *  Created on: 20-Jun-2024
 *      Author: acer
 */

#include "Temperature.h"


Temperature::Temperature(uint16_t timestamp, float temperature):Measurement(timestamp), temperature(temperature)
{
}

float Temperature::getTemperature() const
{
	return temperature;
}

std::string Temperature::toString() const
{
	return ("Temperature: " + std::to_string(getTemperature()) +"°C");
}

std::shared_ptr<Temperature> Temperature::fromString(uint16_t timestamp,
		std::string value)
{
	return std::make_shared<Temperature>(Temperature(timestamp, stof(value)));
}

Temperature::~Temperature()
{
}

