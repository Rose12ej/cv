/* Lab 7 Planets --  A program that asks the user to enter his or her weight and the name of a planet using
functions, a switch statement, and enum types for planets.The program outputs an error message if the user
doesn’t input a correct planet name.
*/

//CSIS 111-002
//<Sources if necessary>
// Brief statement that described program & program logic comments - Prof.Sipantzi

//Include statements
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
enum PlanetType { MERCURY, VENUS, EARTH, MOON, MARS, JUPITER, SATURN, URANUS, NEPTUNE, PLUTO };
float const MERCURY_GRAV = 0.4155, VENUS_GRAV = 0.8975, EARTH_GRAV = 1.0, MOON_GRAV = 0.166, MARS_GRAV = 0.3507, JUPITER_GRAV = 2.5374;
float const SATURN_GRAV = 1.0677, URANUS_GRAV = 0.8947, NEPTUNE_GRAV = 1.1794, PLUTO_GRAV = 0.0899;

//Function prototypes

void wait();
bool validPlanet(string&, PlanetType& );
string convertToUpperCase(string);
float calculateWeight(float, PlanetType);

int main() 
{
	//In cout statement below substitute your name and lab number
	cout << " Rosalia Nunez -- Lab 7" << endl << endl;
	
	//Variable declarations
	string userInput;
	float weight{0};
	PlanetType planet;

	//Program logic
	
	// introduction of program for fun
	cout << " Hello fellow human! Have you ever wondered how much you would weight in another planet?\n Follow the program's instructions and find out!" << endl <<endl;


		// getting user's weight on earth in pounds.
	cout << " Please enter your current weight in pounds: ";
	cin >> weight;


	//Get the user's planet choice as a string
	//	Keep prompting the user until you get a valid planet name 
	do {
		//Prompt user for a planet 
		cout << " Enter the planet that interests you: ";
		cin >> userInput;

	} while (!validPlanet(userInput, planet)); //Use a function to validate the user's planet name and return true if the name is valid and false if not

	//calculate the user's weight on the selected planet in a function
	weight = calculateWeight(weight, planet);

	//Output the result
	cout << "\n YOUR WEIGHT IN " << userInput << " IS " << fixed << setprecision(2) << weight << " POUNDS." << endl;

	wait(); //Halts the program until the user is ready to finish
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
	cout << " Press the Enter key to continue ... ";
	cin.get(ch);
}

string convertToUpperCase(string userInput)
{
	for (int i = 0; i < userInput.size(); i++)
		userInput[i] = toupper(userInput[i]);
	return userInput;

}

bool validPlanet(string& userInput, PlanetType& planet) 
{
	bool returnVal = true;
	userInput = convertToUpperCase(userInput);

	//Identify the user's selected planet and set your planet enum variable accordingly
	if (userInput == "MERCURY")
		planet = MERCURY;
	else if (userInput == "VENUS")
		planet = VENUS;
	else if (userInput == "EARTH")
		planet = EARTH;
	else if (userInput == "MOON")
		planet = MOON;
	else if (userInput == "MARS")
		planet = MARS;
	else if (userInput == "JUPITER")
		planet = JUPITER;
	else if (userInput == "SATURN")
		planet = SATURN;
	else if (userInput == "URANUS")
		planet = URANUS;
	else if (userInput == "NEPTUNE")
		planet = NEPTUNE;
	else if (userInput == "PLUTO")
		planet = PLUTO;
	else
	{
		//If the user does not input a correct planet output an error message
		cout << "\n Invalid answer! Check if you have any spelling errors. For example, 'mercuri' should be spelled 'mercury'!" << endl << endl;
		returnVal = false;
	}

	return returnVal;
}


float calculateWeight(float weight, PlanetType planet)
{
	// initializing float that stores new weight for program readibility and clarity
	float userNewWeight{0};


	switch (planet) {


	case MERCURY:
		userNewWeight = weight * MERCURY_GRAV;
		break;
	case VENUS:
		userNewWeight = weight * VENUS_GRAV;
		break;
	case EARTH:
		userNewWeight = weight * EARTH_GRAV;
		break;
	case MOON:
		userNewWeight = weight * MOON_GRAV;
		break;
	case MARS:
		userNewWeight = weight * MARS_GRAV;
		break;
	case JUPITER:
		userNewWeight = weight * JUPITER_GRAV;
		break;
	case SATURN:
		userNewWeight = weight * SATURN_GRAV;
		break;
	case URANUS:
		userNewWeight = weight * URANUS_GRAV;
		break;
	case NEPTUNE:
		userNewWeight = weight * NEPTUNE_GRAV;
		break;
	default:
		break;
	}

	return userNewWeight;
}
