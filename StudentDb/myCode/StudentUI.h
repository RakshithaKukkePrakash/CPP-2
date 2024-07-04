/*
 * StudentUI.h
 *
 *  Created on: 01-Jul-2024
 *      Author: acer
 */

#ifndef STUDENTUI_H_
#define STUDENTUI_H_
#include <fstream>
#include <Poco/Data/Time.h>
#include "StudentDb.h"
class StudentUI
{
	StudentDb db;
public:
	StudentUI(StudentDb& db);
	void run();
	Poco::Data::Date convertDate(const std::string date);
	Poco::Data::Time convertTime(const std::string time);
	Poco::DateTime::DaysOfWeek convertDayOfWeek(const std::string dow);
	void addCourse();
	virtual ~StudentUI();
};

#endif /* STUDENTUI_H_ */
