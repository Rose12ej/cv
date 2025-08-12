// Grasshopper header file - this a derived class from insects that sets an Grasshopper's size and color and describes what they eat

//libraries
#include <iostream>
#include "Grasshopper.h"

using namespace std;

Grasshopper::Grasshopper(string clr, double sz): Insect(clr, sz)  // default constructor that sets color and size in mm
{
	cout << "Invoking Grasshopper 2-argument constructor." << endl;
}
Grasshopper::~Grasshopper()
{
	cout << "Invoking Grasshopper destructor" << endl;
}
void Grasshopper::eat()
{
	cout << "As a grasshopper, I eat grass and leaves." << endl;
}