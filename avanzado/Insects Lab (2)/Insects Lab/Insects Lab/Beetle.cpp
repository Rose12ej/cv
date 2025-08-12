// Beetle cpp file - this a derived class from insects that sets an Beetle's size and color and describes what they eat

//libraries
#include "Beetle.h"
#include <iostream>

using namespace std;

Beetle::Beetle(string clr, double sz) : Insect(clr, sz)  // default constructor that sets color and size in mm
{
	cout << "Invoking Beetle 2-argument constructor." << endl;
}
Beetle::~Beetle() //default destructor
{
	cout << "Invoking Beetle destructor" << endl;
}
void Beetle::eat() //overrided eat function that states what beetle's eat
{
	cout << "As a beetle, I eat plants and other small insects." << endl;

}
