// Driver cpp - this is a program that uses polymorphism to create insects and stores them in an array.
// Rosalia Nunez
// CSCN 112-002
// April 29, 2023

//libraries
#include <iostream>
#include <random>
#include <iomanip>
#include "Insect.h"
#include "Ant.h"
#include "Beetle.h"
#include "Termite.h"
#include "Grasshopper.h"

using namespace std;

//function prototypes
void printMenu(char& selec); //prints insects menu
void printInsects(Insect** insects); // prints the user's selected insect
void getInsect(string& clr, char& selec); //gets the insect's information ( which insect and its color)

int main()
{
	//variable declarations
	char selec = 0; // insect selection
	string clr; // color of the insect
	Insect **insects = new Insect*[5]; // insect array
	random_device rdevice{}; // random device
	default_random_engine num{ rdevice() }; // seeding number with random device
	uniform_real_distribution<double> randomSizeAnt{0.01,1.00}; // limits size of ant
	uniform_real_distribution<double> randomSizeBeetle{ 40.0,75.5 }; // limits size of beetle
	uniform_real_distribution<double> randomSizeTermite{ 1.5,5.5 }; // limits size of termite
	uniform_real_distribution<double> randomSizeGrasshopper{ 10.5,50.0 }; // limits size of grasshopper

	// main logic
	cout << "\t--Insects Lab--\t" << endl; //program title
	
	for (int i = 0; i < 5; ++i) { //loops until 5 items are saved in insect
		getInsect(clr, selec); //gets insects info. ( color and type)

			if (selec == '1') { //if ant
				Ant* a = new Ant(clr,randomSizeAnt(num)); // dynamically creates an ant & sets its color and a random size
				insects[i] = a; // saves ant in insect array
			}
			else if (selec == '2') { // if grasshopper
				Grasshopper* g = new Grasshopper(clr, randomSizeGrasshopper(num)); // dynamically creates a grasshopper & sets its color and a random size
				insects[i] = g; // saves grasshopper in insect array
			}
			else if (selec == '3') { // if beetle
				Beetle* b = new Beetle(clr, randomSizeBeetle(num)); // dynamically creates a beetle & sets its color and random size
				insects[i] = b; // saves a beetle in insect array
			}
			else if (selec == '4') { // if termite
				Termite* t = new Termite(clr, randomSizeTermite(num)); // dynamically creates an termite sets its color and a random size
				insects[i] = t; // saves termite in insect array
			}
	}
	printInsects(insects); // display all insects in array

	// deleting all pointers created
	for (int i = 0; i < 5; ++i) //loop that deletes pointers in array and sets to null
	{
		delete(insects[i]);
		insects[i] = nullptr;
	}
	delete[] insects; //deleting built-in array pointer
	insects = nullptr; //setting array to null

	//closing statements
	system("pause");
	return 0;
}

//function implementation
void printMenu(char& selec) //prints insects menu
{	// displays menu of insects
	cout << endl << "Main Menu" << endl<< endl;
	cout << "1 - Ant" << endl << endl;
	cout << "2 - Grasshopper" << endl << endl;
	cout << "3 - Beetle" << endl << endl;
	cout << "4 - Termite" << endl << endl;
	cout << "Enter selection: " ;
	cin >> selec; cout << endl; // saves selection
	// error check for invalid character
	if (selec != '1' ){
		if (selec != '2') {
			if (selec != '3') {
				if (selec != '4') {
					cout << "you made an invalid selection!" << endl; // error output
					cin.clear(); // clears cin
					cin.ignore(); //makes cin ignore invalid data
					printMenu(selec); // reproduces function for a new selection
				}
			}
		}
	}
}
void getInsect(string& clr, char& selec) // gets insect's info
{
	printMenu(selec); // prints menu option and gets selection
	cout << "Enter a color for the Insect: "; // prompt for insect's color
	cin.ignore();
	getline(cin, clr); cout << endl << endl; // saves insects color
}
void printInsects(Insect** insects) //gets the insect's information ( which insect and its color)
{
	cout << endl;
	cout << "-----Insects Selected -----" << endl << endl; // title
	for (int i = 0; i < 5; ++i) // loops over all insects in array
	{
		insects[i]->eat(); // display which insect and what it eats
		// displays color and size of the insect
		cout << "My color is " << insects[i]->getColor() << ", and I am " << fixed << setprecision(2) << insects[i]->getSize() << " millimeters long." << endl << endl;
	}
}