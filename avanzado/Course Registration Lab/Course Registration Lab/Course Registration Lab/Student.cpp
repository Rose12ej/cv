// Student class implementation file - is a class that stores student's info 


//libraries
#include "Student.h"
#include "Person.h"
#include <string>
#include <exception>
#include <iomanip>

using namespace std;

Student::Student() //default constructor
{
	GPA = 0;
}
Student::~Student() //default destructor
{
	
}
void Student::setMajor(std::string mj) //sets major
{
	major = mj;
}
void Student::setLevel(std::string lvl) // sets level
{
	level = lvl;
}
void Student::setDateEnrolled(Date d) //sets date enrolled 
{
	dateEnrolled = d;
}
void Student::setGPA(double gpa) //sets gpa 
{
	if (gpa > 4.00) { // error check for more than 4.00
		throw exception("The GPA cannot be greater than 4.00! ");
	}
	else if (gpa < 0) { // error check for negative values
		throw exception("The GPA cannot be a negative value! ");
	}else{
		GPA = gpa;
	}
}
std::string Student::getMajor() const // retrieves major
{
	return major;
}
std::string Student::getLevel() const // retrieves level
{
	return level;
}
Date Student::getDateEnrolled() const // retrieves date enrolled 
{
	return dateEnrolled;
}
double Student::getGPA() const // retrieves gpa
{
	return GPA;
}
ostream& operator<<(ostream& output, Student& s) // overloaded output operator  
{	//outputs and formats all the student's info
	output <<"Student ID:"  << setw(16) << fixed << left << " " << s.getID() << endl;
	output << "Student Name:" << setw(14) << fixed << left << " " << s.getFirstName()<<" " << s.getLastName() << endl;
	output << "Birth Date:" << setw(16) << fixed << left << " " << s.getBirthDate() << endl;
	output << "Date of Enrollment:" << setw(8) << fixed << left << " " << s.getDateEnrolled() << endl;
	output << "Major:" << setw(21) << fixed << left << " " << s.getMajor() << endl;
	output << "Level:" << setw(21) << fixed << left << " " << s.getLevel() << endl;
	output  << "GPA:" << setw(23) << fixed << left << " " << setprecision(2) << s.getGPA() << endl;

	return output;
}
bool Student::operator<(const Student& a) // overloaded less than operator that returns least id
{
	return this->getID() < a.getID();
}
