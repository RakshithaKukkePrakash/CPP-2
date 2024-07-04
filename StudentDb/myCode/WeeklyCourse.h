/*
 * WeeklyCourse.h
 *
 *  Created on: 01-Jul-2024
 *      Author: acer
 */

#ifndef WEEKLYCOURSE_H_
#define WEEKLYCOURSE_H_

#include <Poco/Data/Date.h>
#include <Poco/Data/Time.h>
#include "Course.h"
class WeeklyCourse: public Course
{
	Poco::DateTime::DaysOfWeek dayOfWeek;
	Poco::Data::Time startTime;
	Poco::Data::Time endTime;
public:
	WeeklyCourse(unsigned int courseKey, std::string title,
			std::string majorStr, float creditPoints, Poco::DateTime::DaysOfWeek,
			Poco::Data::Time startTime, Poco::Data::Time endTime);
	virtual ~WeeklyCourse();
};

#endif /* WEEKLYCOURSE_H_ */
