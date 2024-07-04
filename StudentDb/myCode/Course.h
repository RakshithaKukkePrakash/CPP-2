/*
 * Course.h
 *
 *  Created on: 01-Jul-2024
 *      Author: acer
 */

#ifndef COURSE_H_
#define COURSE_H_
#include <iostream>
#include <map>
class Course
{
	static std::map<unsigned char, std::string> majorById;
	unsigned int courseKey;
	std::string title;
	unsigned char major;
	float creditPoints;
public:
	Course(unsigned int courseKey, std::string title, std::string majorStr,float creditPoints);
	virtual ~Course() = 0;
};

#endif /* COURSE_H_ */
