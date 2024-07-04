/*
 * StudentDb.cpp
 *
 *  Created on: 01-Jul-2024
 *      Author: acer
 */

#include "StudentDb.h"

StudentDb::StudentDb()
{
	// TODO Auto-generated constructor stub

}

StudentDb::~StudentDb()
{
	// TODO Auto-generated destructor stub
}

void StudentDb::addBlockedCourse(unsigned int courseKey, std::string title,
		std::string majorStr, float creditPoints, Poco::Data::Date startDate,
		Poco::Data::Date endDate, Poco::Data::Time startTime,
		Poco::Data::Time endTime)
{
	this->courses.insert(
			std::make_pair(courseKey,
					std::make_unique<BlockCourse>(courseKey, title, majorStr, creditPoints,
			startDate, endDate, startTime, endTime)));
}

void StudentDb::addWeeklyCourse(unsigned int courseKey, std::string title,
		std::string majorStr, float creditPoints,
		Poco::DateTime::DaysOfWeek daysOfWeek, Poco::Data::Time startTime,
		Poco::Data::Time endTime)
{
	this->courses.insert(std::make_pair(courseKey, std::make_unique<WeeklyCourse>(courseKey, title, majorStr, creditPoints,
			daysOfWeek, startTime, endTime)));
}
