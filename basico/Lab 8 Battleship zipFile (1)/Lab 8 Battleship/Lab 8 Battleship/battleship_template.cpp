/*
	Imagine we are using a two-dimensional array as the basis for creating the game battle- ship. In the game of battleship a ‘~’ character entry in the array represents ocean (i.e., not a ship), a ‘#’ character represents a place in the ocean where part of a ship is present, and a ‘H’ character represents a place in the ocean where part of a ship is present and has been hit by a torpedo. Thus, a ship with all ‘H’ characters means the ship has been sunk. Declare a two-dimensional char array that is 25 by 25 that represents the entire ocean and an If statement that prints “HIT” if a torpedo hits a ship given the coordinates X and Y. Write a C++ program that will read in a file representing a game board with 25 lines where each line has 25 characters corresponding to the description above. 
	
	You should write a function called fire() that will take an X and Y coordinate and print “HIT” if a ship is hit and “MISS” if a ship is missed. If a ship is HIT you should update the array with an ‘H’ character to indicate the ship was hit. If a ship is hit that has already been hit at that location you should print “HIT AGAIN”. You should write a second function called fleetSunk that will determine if all the ships have been sunk. Your C++ program must then call these functions until all the ships have been sunk at which point the program should display “The fleet was destroyed!”.

	Your game loop logic (the main logic of a game) should like like the following:

    do {
        fire(x, y, gameBoard);
    } while(!fleetSunk(gameBoard));
*/

//Include statements
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables

//Function prototypes
void wait();
void fire(int x, int y, char gameboard[25][25], char hiddenBoard[25][25]);
bool fleetSunk(char gameboard[25][25]);
void printArray(char ary[25][25], int numRows, int numCols);



int main() 
{
	//In cout statement below substitute your name and lab number
	cout << "Rosalia Nunez -- Lab 8" << endl << endl;
	
	//Variable declarations
	string fileName;
	int x, y;
	char hiddenGameboard[25][25]; // two dimensional array that represents board with the boats.
	char gameboard[25][25]; // two dimensional char array that is 25 by 25 that represents the entire ocean
	//Program logic

	//reading in file with empty board game for player to use
	ifstream insideFile("gamersboard.txt");
	
	if (insideFile) {
		for (int row = 0; row < 25; row++)
		{
			for (int col = 0; col < 25; col++) {
				insideFile >> gameboard[row][col];
			}
		}
	}else
	{
		cout << "An error has occured with the program!" << endl;
		return 0;
	}

	// printing rules of the game
	cout << "Hello player!! Welcome to the BATTLESHIP GAME!!!" << endl; 
	cout << "You will be asked to enter a file with the boats in the ocean." << endl;
	cout << "This file should be created by someone other than you" << endl;
	cout << "and have a array of 25 by 25 characters." << endl;
	cout << "They have to hide their boats in the ocean!" << endl;
	cout << "You have to attempt to hit their boats with this program!!!" << endl << endl;

	cout <<"...Rules of the Game..." << endl;
	cout <<"In the game of battleship a '~' character entry in the array represents ocean (i.e., not a ship),"<<endl;
	cout <<"a '#' character represents a place in the ocean where part of a ship is present,"<< endl;
	cout <<"and a 'H' character represents a place in the ocean where part of a ship is present and has been hit by a torpedo."<< endl;
	cout <<"Thus, a ship with all 'H' characters means the ship has been sunk." << endl<< endl;
		
	// read in a file representing a board game from user
	cout << "Enter the name of the input file where the gameboard is stored	(remember to add the file extension):";
	cin >> fileName;
	ifstream inFile(fileName);

	if (inFile)
	{

		for (int row = 0; row < 25; row++)
		{
			for (int col = 0; col < 25; col++) {
				inFile >> hiddenGameboard[row][col];
			}
		}
		cout << "Your file was entered! Now, Let the games begin!!!" << endl;

		// printing empty gameboard to start game 

		do {
		//presenting board game
			cout << "\nThis is your boardgame." << endl;
			printArray(gameboard, 25, 25);

			// asking user for coordinates
			
				cout << "Enter the coordinates where you will like to shoot your torpedo." << endl;
				cout << "(the coordinates are two number from 0-24 separated by a space):" << endl;
				cout << "The first value consist of the rows in the gameboard and the second value consist of the collumns." << endl;
				cin >> x >> y;

			// invalid answer response reply
				if (x >= 25 || y >= 25)
				{
					cout << "Invalid answer!" << endl;
					cout << "Enter the coordinates where you will like to shoot your torpedo." << endl;
					cout << "(the coordinates are two numbers from 0-24 separated by a space):" << endl;
					cin >> x >> y;
				}else

			

			//calling function fire()
			fire(x, y, gameboard, hiddenGameboard);

			//calling function fleetSunk()
		} while (!fleetSunk(hiddenGameboard));

		// should display “The fleet was destroyed!”
		cout << "\nThe fleet was destroyed!" << endl;

	}
	else
	{
		cout << "The file could not be opened." << endl;
	}

	// closing opened files
	inFile.close();
	insideFile.close();
	
	//Closing program statements
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
	cout << "Press the Enter key to continue ... ";
	cin.get(ch);
}

void fire(int x, int y, char gameboard[25][25], char hiddenBoard[25][25])
{  //write a function called fire() that will take an X and Y coordinate and print “HIT” if a ship is hit
	//and “MISS” if a ship is missed
	//variables
	char hit = 'H';
	char boat = '#';
	
		 if (hiddenBoard[x][y] == hit)
		{
			//If a ship is hit that has already been hit at that location you should print “HIT AGAIN”
			cout << "HIT AGAIN!" << endl;
		}else if (hiddenBoard[x][y] == boat)
		{
			//update the array with an ‘H’ character to indicate the ship was hit.
			gameboard[x][y] = hit;
			hiddenBoard[x][y] = hit;
			cout << "HIT!" << endl;
		}
		else
		{ //and “MISS” if a ship is missed
			cout << "MISS!" << endl;
		}
	
}

bool fleetSunk(char hiddenBoard[25][25]) {
	bool isSunk = false;
	char boat = '#';
	char sea = '~';
	
	//determine if all the ships have been sunk
	
		
	for (int x = 0; x < 25; x++) {
		for (int y = 0; y < 25; y++) {


			if (hiddenBoard[x][y] == boat)
			{
				return false;
			}
		}
	}
		
	return true;
}

void printArray(char ary[25][25], int numRows, int numCols)
{
	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {
			cout << ary[row][col];
		}cout << endl;
	}
}
