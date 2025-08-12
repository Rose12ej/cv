//Dictionary-bag implementation which must inherit the Dictionary class
// Ferbruary 7, 2023
// edited by Rose

#pragma once

//libraries
#include "dictionaryADT.h"
#include "ABag.h"
#include "kvpair.h"
#include <memory>

template<class Key,class E>
class BDictionary : public Dictionary<Key,E>
{
public:
	BDictionary() { //default constructor 
		dictionary = std::make_unique<ABag<KVpair<Key, E>>>();
	}

	BDictionary(int size) { //default constructor 
		dictionary = std::make_unique<ABag<KVpair<Key, E>>>(size);
	}

	~BDictionary() {} //default destructor

	// Reinitialize dictionary
	void clear(){
		dictionary->emptyBag();
    }

	// Insert a record
	bool insert(const Key& k, const E& e)
	{
		KVpair<Key, E> item(k, e);
		return dictionary->addItem(item);
	}

	// Looks for a record using the key 
	bool remove(const Key& k, E& rtnVal)
	{
		KVpair<Key, E> item(k, rtnVal);
		bool x = dictionary->remove(item); //removes item
		rtnVal = item.value(); //stores value
		return x; //marks if removed
	}

	// Takes an arbitrary record from the dictionary
    bool removeAny(E& returnValue)
	{
		KVpair<Key, E> item;
		bool x = dictionary->removeTop(item);  //removes top item
		returnValue = item.value(); //saves item
		return x;
	}

	// Looks for a record using the key
	bool find(const Key& k, E& returnValue) const
	{
		KVpair<Key, E> item(k,returnValue);
		bool x = dictionary->search(item); //finds item
		returnValue = item.value(); //saves item
		return x;
	}

	// Return the number of records in the dictionary.
    int size() const
	{
		return dictionary->numItems();
	}

private:
	std::unique_ptr<ABag<KVpair<Key, E>>> dictionary; // dictionary with smart pointer
};	

