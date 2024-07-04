/*
 * BlockCourse.h
 *
 *  Created on: 01-Jul-2024
 *      Author: acer
 */

#ifndef BLOCKCOURSE_H_
#define BLOCKCOURSE_H_

#include <Poco/Data/Date.h>
#include <Poco/Data/Time.h>
#include "Course.h"

class BlockCourse: public Course
{
	Poco::Data::Date startDate;
	Poco::Data::Date endDate;
	Poco::Data::Time startTime;
	Poco::Data::Time endTime;
public:
	BlockCourse(unsigned int courseKey, std::string title,
			std::string majorStr, float creditPoints, Poco::Data::Date startDate,
			Poco::Data::Date endDate, Poco::Data::Time startTime,
			Poco::Data::Time endTime);
	virtual ~BlockCourse();
};

#endif /* BLOCKCOURSE_H_ */
