/*
 * Enrollment.h
 *
 *  Created on: 01-Jul-2024
 *      Author: acer
 */

#ifndef ENROLLMENT_H_
#define ENROLLMENT_H_
#include "Course.h"
#include <iostream>
class Enrollment
{
	float grade;
	std::string semester;
	Course* course;

public:
	Enrollment();
	virtual ~Enrollment();
};

#endif /* ENROLLMENT_H_ */
