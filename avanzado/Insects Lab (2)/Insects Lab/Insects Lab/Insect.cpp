// Insects cpp file - this is an abstract base class that stores an insects size and color 

//libraries
#include "Insect.h"
#include <iostream>
#include <exception>

using namespace std;


Insect::Insect() //default constructor
{
	size = 0;
	cout << "Invoking the default Insect constructor" << endl;
}
Insect::Insect(std::string clr, double sz) // constructor that sets color and size
{
	color = clr;
	setSize(sz);
	cout << "Invoking the 2-argument Insect constructor." << endl;
}
Insect::~Insect() // default destructor
{
	cout << "Invoking the default Insect destructor." << endl;
}
void Insect::setColor(std::string clr) // sets color of insect
{
	color = clr;
}
std::string Insect::getColor() //gets color
{
	return color;
}
void Insect::setSize(double sz) // sets size in millimeters
{
		size = sz;
}
double Insect::getSize() // gets size
{
	return size;
}
