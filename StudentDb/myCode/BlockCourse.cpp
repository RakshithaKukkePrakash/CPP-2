/*
 * BlockCourse.cpp
 *
 *  Created on: 01-Jul-2024
 *      Author: acer
 */

#include "BlockCourse.h"


BlockCourse::BlockCourse(unsigned int courseKey, std::string title,
		std::string majorStr, float creditPoints, Poco::Data::Date startDate,
		Poco::Data::Date endDate, Poco::Data::Time startTime,
		Poco::Data::Time endTime): Course(courseKey, title, majorStr, creditPoints),
				startDate(startDate), endDate(endDate), startTime(startTime), endTime(endTime)
{
}

BlockCourse::~BlockCourse()
{
	// TODO Auto-generated destructor stub
}

