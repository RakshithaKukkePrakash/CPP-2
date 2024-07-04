/*
 * WeeklyCourse.cpp
 *
 *  Created on: 01-Jul-2024
 *      Author: acer
 */

#include "WeeklyCourse.h"

WeeklyCourse::WeeklyCourse(unsigned int courseKey, std::string title,
		std::string majorStr, float creditPoints,
		Poco::DateTime::DaysOfWeek daysOfWeek, Poco::Data::Time startTime,
		Poco::Data::Time endTime): Course(courseKey, title, majorStr, creditPoints),
		dayOfWeek(daysOfWeek), startTime(startTime), endTime(endTime)
{
}

WeeklyCourse::~WeeklyCourse()
{
	// TODO Auto-generated destructor stub
}

