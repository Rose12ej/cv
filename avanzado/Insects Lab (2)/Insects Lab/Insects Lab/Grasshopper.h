// Grasshopper header file - this a derived class from insects that sets an Grasshopper's size and color and describes what they eat

#pragma once

//libraries
#include <string>
#include "Insect.h"

class Grasshopper : public Insect
{
public:
	Grasshopper(std::string clr = "", double sz=0);  // default constructor that sets color and size in mm
	~Grasshopper(); //default destructor
	void eat(); //overrided eat function that states what a grasshopper eats
};
