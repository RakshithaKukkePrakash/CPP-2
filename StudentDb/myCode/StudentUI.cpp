/*
 * StudentUI.cpp
 *
 *  Created on: 01-Jul-2024
 *      Author: acer
 */

#include "StudentUI.h"
using namespace std;

StudentUI::StudentUI(StudentDb &db):db(db)
{

}

void StudentUI::run()
{
	int operation;
	cout<< "Select an operation with its ID"<<endl;
	cout<< "1. Add new Course "<<endl<< "2. List courses " <<endl<< "3. Add new Student "<<endl <<"4. Add enrollment "<<endl;
	cout<< "5. Print student "<<endl<< "6. Search student " <<endl<< "7. Update Student "<<endl <<"8. Write to file "<<endl <<"9. Read from file "<<endl;
	cin >> operation;
}

void StudentUI::addCourse()
{
	unsigned int courseKey;
	std::string title;
	std::string majorStr;
	unsigned int majorChoice;
	float creditPoints;
	int choice;
	cout<< "Select 1 for block course and 2 for weekly course"<<endl;
	cin >> choice;
	cout<< "Enter course key"<<endl;
	cin >> courseKey;
	cout<< "Enter course title"<<endl;
	cin.ignore();
	getline(cin, title);
	cout<< "Enter course credit point"<<endl;
	cin >> creditPoints;
	map<int, string> majors =
	{
	{ 1, "Automation" },
	{ 2, "Communication" },
	{ 3, "Embedded" },
	{ 4, "Power" },
	{ 5, "Others" } };
	cout<< "Enter the major"<<endl;
	cin >> majorChoice;
	auto itr = majors.find(majorChoice);
	if(itr!= majors.end()){
		majorStr = itr->second;
	}
	if(majorChoice)
	switch(choice){
	case 1: // Block Course
		{
			string date;

		Poco::Data::Date startDate, endDate;
		cout<< "Enter start date in format DD:MM:YYYY"<<endl;
		cin >> date;
		startDate = convertDate(date);
		cout<< "Enter end date in format DD:MM:YYYY"<<endl;
		cin >> date;
		endDate = convertDate(date);
		string time;
		Poco::Data::Time startTime, endTime;
		cout<< "Enter start time in format HH:MM"<<endl;
		cin >> time;
		startTime = convertTime(time);
		cout<< "Enter end time in format HH:MM"<<endl;
		cin >> time;
		endTime = convertTime(time);

		db.addBlockedCourse(courseKey, title, majorStr, creditPoints,
				startDate, endDate, startTime, endTime);
		}
		break;

	case 2:// Weekly Course
	{
		string time;
		Poco::Data::Time startTime, endTime;
		Poco::DateTime::DaysOfWeek dow;
		cout<< "Enter day of the week"<<endl;
		cin >> time;
		dow= convertDayOfWeek(time);
		cout<< "Enter start time in format HH:MM"<<endl;
		cin >> time;
		startTime = convertTime(time);
		cout<< "Enter end time in format HH:MM"<<endl;
		cin >> time;
		endTime = convertTime(time);

		db.addWeeklyCourse(courseKey, title, majorStr,creditPoints,
				dow, startTime, endTime);

	}
		break;

	}
}



Poco::Data::Date StudentUI::convertDate(const std::string date)
{
	int year, month, day;
	sscanf(date.c_str(),"%d:%d:%d", &day, &month, &year);
	Poco::Data::Date newDate(year, month, day);
	return newDate;
}

Poco::Data::Time StudentUI::convertTime(const std::string time)
{
	int hour, minute;
	sscanf(time.c_str(),"%d:%d", &hour, &minute);
	Poco::Data::Time timeNew(hour, minute, 0);
	return timeNew;
}

Poco::DateTime::DaysOfWeek StudentUI::convertDayOfWeek(const std::string dow)
{
	string day;
	for (char &i : day)
	{
		i = toupper(i);
	}
	if (dow == "MONDAY")
	    return Poco::DateTime::DaysOfWeek::MONDAY;
	else if (dow == "TUESDAY")
	    return Poco::DateTime::DaysOfWeek::TUESDAY;
	else if (dow == "WEDNESDAY")
	    return Poco::DateTime::DaysOfWeek::WEDNESDAY;
	else if (dow == "THURSDAY")
	    return Poco::DateTime::DaysOfWeek::THURSDAY;
	else if (dow == "FRIDAY")
	    return Poco::DateTime::DaysOfWeek::FRIDAY;
	else if (dow == "SATURDAY")
	    return Poco::DateTime::DaysOfWeek::SATURDAY;
	else if (dow == "SUNDAY")
	    return Poco::DateTime::DaysOfWeek::SUNDAY;
	else
	    return Poco::DateTime::DaysOfWeek::SUNDAY;

}

StudentUI::~StudentUI()
{
}

