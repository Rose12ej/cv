// Faculty class header file - is a class that stores faculty's info 

#pragma once

//libraries
#include "Person.h"
#include "Date.h"
#include <string>

class Faculty : public Person //derived class from person
{
	friend std::ostream& operator<<(std::ostream&, Faculty&); // overloaded output operator
public:
	Faculty(); // default constructor
	Faculty(Date bD, std::string fn, std::string ln, std::string id) :Person(bD, fn, ln, id) //constructor that sets birthday, first and last name, and id
	{
		salary = 0;
	}
	~Faculty();// default destructor
	void setTitle(std::string ttl); // sets title
	void setRank(std::string rnk); // sets rank
	void setDateHired(Date d); // sets date hired
	void setSalary(double slry); // sets salary
	std::string getTitle() const; // retrieves title
	std::string getRank() const; // retrieves rank
	Date getDateHired() const; // retrieves date hired
	double getSalary() const; // retrieves salary
private:
	std::string title; // professor's title
	std::string rank; // rank
	Date dateHired; // date hired
	double salary; //salary
};