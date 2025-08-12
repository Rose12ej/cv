// Termite header file - this a derived class from insects that sets an Termite's size and color and describes what they eat

//libraries
#include <iostream>
#include "Termite.h"

using namespace std;

Termite::Termite(string clr, double sz) : Insect(clr, sz) // default constructor that sets color and size in mm
{
	cout << "Invoking Termite 2-argument constructor." << endl;
}
Termite::~Termite() //default destructor
{
	cout << "Invoking Termite destructor" << endl;
}
void Termite::eat() // overrided eat function that states what a termite eats 
{
	cout << "As a termite, I eat wood." << endl;

}