/*
 * Course.cpp
 *
 *  Created on: 01-Jul-2024
 *      Author: acer
 */

#include "Course.h"
using namespace std;
map<unsigned char, string> Course::majorById = {
		{'A', "Automation"},
		{'E', "Embedded"},
		{'P', "Power"},
		{'C', "Communication"},
		{'O', "Others"}
};



Course::Course(unsigned int courseKey, std::string title, std::string majorStr,
		float creditPoints): courseKey(courseKey), title(title), creditPoints(creditPoints)
{
	for (const auto &pair : majorById)
	{
		if(majorStr == pair.second)
		{
			this->major = pair.first;
		}
	}
}

Course::~Course()
{
	// TODO Auto-generated destructor stub
}
