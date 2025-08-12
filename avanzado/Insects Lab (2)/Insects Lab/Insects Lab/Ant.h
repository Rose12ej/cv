// Ant header file - this a derived class from insects that sets an ant's size and color and describes what they eat

#pragma once

//libraries
#include <string>
#include "Insect.h"

class Ant : public Insect
{
public:
	Ant(std::string clr = "", double sz = 0); // default constructor that sets color and size in mm
	~Ant(); // default destructor
	void eat(); // overrided eat function that states what insects eats
};
