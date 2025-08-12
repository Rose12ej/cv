// Beetle header file - this a derived class from insects that sets an Beetle's size and color and describes what they eat

#pragma once

//libraries
#include <string>
#include "Insect.h"

class Beetle : public Insect
{
public:
	Beetle(std::string clr = "", double sz = 0);  // default constructor that sets color and size in mm
	~Beetle(); // default destructor 
	void eat(); // overrided eat function that states what beetle's eat.
};