// Termite header file - this a derived class from insects that sets an Termite's size and color and describes what they eat

#pragma once

//libraries
#include <string>
#include "Insect.h"

class Termite : public Insect
{
public:
	Termite(std::string clr = "", double sz = 0); // default constructor that sets color and size in mm
	~Termite(); // default destructor
	void eat(); // overrided eat function that states what a termite eats.
};
