// Faculty class implementation file - is a class that stores faculty's info 

#include "Faculty.h"
#include <iostream>
#include <iomanip>
#include <exception>

using namespace std;

Faculty::Faculty() // stores faculty
{
	salary = 0;
}
Faculty::~Faculty() // default destructor
{

}
void Faculty::setTitle(std::string ttl) // sets title
{
	title = ttl;
}
void Faculty::setRank(std::string rnk) // sets rank
{
	rank = rnk;
}
void Faculty::setDateHired(Date d) // sets date hired
{
	dateHired = d;
}
void Faculty::setSalary(double slry) // sets salary
{
	if (slry > 0)
	{
		salary = slry;
	}
	else { // error check for negative number
		throw exception("The salary cannot be a negative value. ");
	}
}
std::string Faculty::getTitle() const // retrieves title
{
	return title;
}
std::string Faculty::getRank() const // retrieves rank
{
	return rank;
}
Date Faculty::getDateHired() const // retrieves date hired
{
	return dateHired;
}
double Faculty::getSalary() const // retrieves salary
{
	return salary;
}
ostream& operator<<(ostream& output, Faculty& f) // overloaded output that outputs and formats faculty info
{
	 
	output << "Instructor:" << endl;
	output << "Faculty ID:" << setw(16) << fixed << left << " " << f.getID() << endl;
	output << "Faculty Name:" << setw(14) << fixed << left << " " << f.getTitle() << " " << f.getFirstName() << " " << f.getLastName() << ", " << f.getRank() << endl;
	output << "Birth Date:" << setw(16) << fixed << left << " " << f.getBirthDate() << endl;
	output << "Date Hired:" << setw(16) << fixed << left << " " << f.getDateHired() << endl;
	output << "Salary:" << setw(20) << fixed << left << " " << setprecision(2) << f.getSalary() << endl;

	return output;
} 
