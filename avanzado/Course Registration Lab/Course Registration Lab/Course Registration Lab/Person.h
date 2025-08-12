//Person Class header file - stores and retrieves basic personal information of a person.

#pragma once

//libraries
#include "Date.h"
#include <string>

class Person
{
public:
	Person(); // default constructor
	Person(Date bD, std::string fn = "", std::string ln = "", std::string id = ""); // constructor
	~Person(); //default destructor
	void setID(std::string id); //stores the id of the person 
	void setFirstName(std::string fName); //stores the first name 
	void setLastName(std::string lname); //stores the last name 
	void setBirthDate(Date bDate); //stores the birthdate 
	std::string getID() const; //retrieves the id
	std::string getFirstName() const; //retrieves the first name 
	std::string getLastName() const; //retrieves the last name
	Date getBirthDate() const; //retrieves the birthdate of
private:
	std::string ID; //id of person
	std::string firstName; // first name of the person
	std::string lastName; // last name of the peron
	Date birthDate;  // birthdate of the person
};

