/*
 * Student.h
 *
 *  Created on: 01-Jul-2024
 *      Author: acer
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <vector>
#include "Enrollment.h"
#include <Poco/Data/Date.h>
class Student
{
	static unsigned int nextMatrikelNumber;
	unsigned int matrikelNumber;
	std::string firstName;
	std::string lastName;
	Poco::Data::Date dateOfBirth;
	std::vector<Enrollment> enrollments;
public:
	Student();
	virtual ~Student();
};

#endif /* STUDENT_H_ */
