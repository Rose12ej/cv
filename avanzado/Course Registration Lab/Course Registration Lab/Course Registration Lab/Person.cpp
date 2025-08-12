//Person Class cpp file - function implementation of class that stores and retrieves basic personal information for students and faculty.

//libraries
#include "Person.h"
#include <iostream>

using namespace std;

//class implementation
Person::Person() // default constructor
{

}
Person::Person(Date bD, string fn, string ln, string id ) // constructor
{
	setFirstName(fn);
	setLastName(ln);
	setID(id);
	setBirthDate(bD);
}
Person::~Person()  //default destructor
{
}
void Person::setID(string id) //stores the id 
{
	ID = id;
}
void Person::setFirstName(string fName) //stores the first name 
{
	firstName = fName;
}
void Person::setLastName(string lname) //stores the last name 
{
	lastName = lname;
}
void Person::setBirthDate(Date bDate) //stores the birthdate 
{
	birthDate = bDate;
}
string Person::getID() const  //retrieves the id 
{
	return ID;
}
string Person::getFirstName() const  //retrieves the first name 
{
	return firstName;
}
string Person::getLastName() const  //retrieves the last name
{
	return lastName;
}
Date Person::getBirthDate() const  //retrieves the birthdate 
{
	return birthDate;
}
