//bag-array implementation which must the bag class
// february 7, 2023 
//edited by Rose

#pragma once

//libraries
#include "bagADT.h"

//class
template<class E>
class ABag:public Bag<E>
{
public:
	ABag() {
		bag = new E[10]; // creating array to hold items
		// initializing values
		maxCap = 10;
		numI = 0;

	}; // default constructor

	ABag(int size) {
		bag = new E[size]; // creating array to hold items
		// initializing values
		maxCap = size;
		numI = 0;

	}; //constructor

	~ABag() {
		delete[] bag;
	}; //destructor

	// Insert a new item into the bag 
	bool addItem(const E& item)
	{	
		bool isAdded = false; //confirms if succesful addition
		if (numI < maxCap)
		{
			bag[numI] = item; //adds item
			numI++; // records new item inserted
			isAdded = true; // notifies succesful addition
		}
		return isAdded; 
	}

	// removes item from list
    bool remove(E& item)
	{
		bool isRemoved = false; //confirms if removed

		for (int i = 0; i < maxCap; i++) // looks for item in bag
		{
			if (item == bag[i]) 
			{
				item = bag[i]; //updates item with bag values
				while (i < numI) 
				{
					bag[i] = bag[i++]; //deletes the item & shifts other items
				}
				numI--; //deletes record of item
				isRemoved = true;
			}
		}
		return isRemoved;
	}

	// Removes the top record from the bag
    bool removeTop(E& returnValue)
	{
		bool isRemoved = false;
		if (numI != 0) { // if bag is not empty
			int i = numI - 1;
			returnValue = bag[i]; //puts top record in variable
			numI--; //removes top record
			isRemoved = true;
		}
		return isRemoved;
	}

	// Finds the record using returnValue 
	bool search(E& returnValue) const
	{
		bool isFound = false;

		for (int i = 0; i < maxCap; i++) // looks for item in bag
		{
			if (returnValue == bag[i]) //compares item
			{
				returnValue = bag[i]; //updates value with item in bag
				isFound = true; // marks as found
			}
		}
		return isFound;
	}

	// Inspect the top of the bag. 
	bool inspectTop(E& item) const
	{
		bool isInspected = false;
		if (numI != 0) //checks if bag is empty
		{	
			int i = numI - 1;
			item = bag[i]; //stores item in the top
			isInspected = true;
		}
		return isInspected;
	}

	// empties the bag
	virtual void emptyBag()
	{
		numI = 0; 
	}

	// uses the += operator to add an item to the bag
	bool operator+=(const E& addend)
	{
		return addItem(addend); //adds item and returns if succesful
	}

	// get the number of items in the bag
    int numItems() const
	{
		return numI;
	}

	// get the capacity of the bag (size of your bag's array)
	int bagCapacity() const
	{
		return maxCap;
	}

private:
	E* bag; // dynamic bag of any datatype chose by the user
	int maxCap; // maximum capacity of items
	int numI; //curent number of items

};
