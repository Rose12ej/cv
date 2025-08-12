// Insects header file - this is an abstract base class that stores an insects size and color 

#pragma once

//libraries
#include <string>

class Insect
{
public:
	Insect(); // default constructor
	Insect(std::string clr, double sz); // constructor that sets the size and color
	virtual ~Insect(); // default destructor 
	virtual void eat() = 0 {}; //purely virtual eat function
	void setColor(std::string clr); // sets the color 
	std::string getColor(); //gets color 
	void setSize(double sz); // sets size
	double getSize(); //gets size
	
private:
	double size; // size in millimeters of insects
	std::string color; // color of insects
};
