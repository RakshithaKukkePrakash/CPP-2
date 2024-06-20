// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
using namespace std;

// Add your project's header files here
#include "Temperature.h"
#include "MeasurementDb.h"
#include "Humidity.h"
#include "Measurement.h"
// Main program
int main ()
{
    // TODO: Add your program code here
	cout << "Rakshitha Kukke Prakash, 1127988" << endl << endl;
	Temperature measurement1(Measurement::toTimestamp(6,0), -3);
	cout<< measurement1;
	MeasurementDb measDb;
	cout<< endl;
	std::shared_ptr<Measurement> m1 = std::make_shared<Humidity> (Measurement::toTimestamp(8,0), 80);
	measDb.addMeasurement("Bath", m1);
	std::shared_ptr<Measurement> m2 = std::make_shared<Temperature> (Measurement::toTimestamp(10,5), 20);
	measDb.addMeasurement("Kitchen", m2);
	std::shared_ptr<Measurement> m3 = std::make_shared<Temperature> (Measurement::toTimestamp(12,0), 22);
	measDb.addMeasurement("Kitchen", m3);
	measDb.print();
	std::string fileName = "data.txt";
	std::ofstream outFile("data.txt", ios::trunc);
	if(outFile.is_open())
	{
		measDb.save(outFile);
	}
	return 0;
}
