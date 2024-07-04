/*
 * StudentDb.h
 *
 *  Created on: 01-Jul-2024
 *      Author: acer
 */

#ifndef STUDENTDB_H_
#define STUDENTDB_H_

#include <map>
#include <memory>
#include <fstream>
#include <sstream>
#include "Address.h"
#include "Student.h"
#include "Enrollment.h"
#include "Course.h"
#include "BlockCourse.h"
#include "WeeklyCourse.h"

class StudentDb
{
	std::map<int, Student> students;
	std::map<int, std::unique_ptr<const Course>> courses;
public:
	StudentDb();
	void addBlockedCourse(unsigned int courseKey, std::string title,
			std::string majorStr, float creditPoints, Poco::Data::Date startDate,
			Poco::Data::Date endDate, Poco::Data::Time startTime,
			Poco::Data::Time endTime);
	void addWeeklyCourse(unsigned int courseKey, std::string title,
			std::string majorStr, float creditPoints,
			Poco::DateTime::DaysOfWeek daysOfWeek, Poco::Data::Time startTime,
			Poco::Data::Time endTime);
	virtual ~StudentDb();
};

#endif /* STUDENTDB_H_ */
