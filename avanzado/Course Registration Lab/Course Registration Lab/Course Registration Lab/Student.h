// Student class header file - is a class that stores student's info 

 #pragma once

//libraries
#include "Person.h"
#include "Date.h"
#include <string>

class Student : public Person // derived class from person
{
	friend std::ostream& operator<<(std::ostream&, Student&); //overloaded << operator
public: 
	Student(); //default constructor
	Student(Date bD, std::string fn, std::string ln, std::string id) : Person(bD, fn, ln, id) //constructor that sets birthday, first and last name, and id
	{
		GPA = 0;
	}
	~Student(); //destructor
	void setMajor(std::string mj); // sets major
	void setLevel(std::string lvl); // sets the level (ex. freshman)
	void setDateEnrolled(Date d); // sets date enrolled
	void setGPA(double gpa); //sets gpa
	std::string getMajor() const; //retrieves major
	std::string getLevel() const; // retrieves level
	Date getDateEnrolled() const; // retrieves date enrolled
	double getGPA() const; // retrieves GPA
	bool operator<(const Student& a); // overloaded < operator
private:
	std::string major; // student's major
	std::string level; // student's level
	Date dateEnrolled; // date enrolled 
	double GPA; // gpa
};