// Ant cpp file - this a derived class from insects that sets an ant's size and color and describes what they eat

//libraries
#include "Ant.h"
#include <iostream>

using namespace std;

Ant::Ant(string clr , double sz) : Insect(clr, sz)  // default constructor that sets color and size in mm
{
	cout << "Invoking Ant 2-argument constructor." << endl;
}
Ant::~Ant() // default destructor
{
	cout << "Invoking Ant destructor" << endl;
}
void Ant::eat() //overrided eat function that displays what an ant eats
{
	cout << "As an ant, I eat everything." << endl;
}