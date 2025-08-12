//car_range.cpp -- Write a program that prompts the capacity, in gallons, of an automobile fuel tank 
//	and the miles per gallon the automobile can be driven. The program outputs the number of miles 
//	the automobile can be driven without refueling.
//CSIS 111-<Section Number>
//<Sources if necessary>


//Include statements
#include <iostream>
#include <string>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables

//Function prototypes
void wait();

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "<Rosalia Nunez -- Lab 3>" << endl << endl;

	//Variable declarations
	int tankCapacity;
	int milesPerGallon;
	int range;

	//Program logic
	//	Prompt user for tank capacity and miles per gallon
	cout << "Enter gas tank capacity of an automobile: " << endl;
	cin >> tankCapacity;
	cout << "Now enter the miles per gallon the automobile can be driven: " << endl;
	cin >> milesPerGallon;

	//	Calculate the car's range and assign it to the variable range

	cout << "\nCalculating..." << endl ;
	range = milesPerGallon * tankCapacity;
	wait();

	//	Output the cars range as well as what the user entered.
	cout << "\nYou entered the following information: " << endl;
    cout << "Gas Tank Capacity: " << tankCapacity << " gal. \nMiles per gallon car: " << milesPerGallon << " mi/gal." << endl << endl;
	cout << "The number of miles the automobile can be driven without refueling is " << range << " miles." << endl << endl;

	//Closing program statements
	wait();
	return 0;
}

//Function Definitions
void wait()
{
	//The following if-statement checks to see how many characters are in cin's buffer
	//If the buffer has characters in it, the clear and ignore methods get rid of them.
	if (cin.rdbuf()->in_avail() > 0) //If the buffer is empty skip clear and ignore
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clear the input buffer 
	}
	char ch;
	cout << "Press the Enter key to continue ... ";
	cin.get(ch);
}


