#pragma once


//libraries
#include "Graph.h"
#include <iostream>

//MST
class MST:private Graph
{
public:
	//constructor
	MST(){ 
		for (int i = 0; i < 6; i++)
		{
			V[i] = false;
			D[i] = 9999; 
			F[i] = 0;
		}

	}
	~MST(){}
	
	//reads graph from a file
	void rGraph(std::string filename)
	{
		readGraph(filename);
		gr = getGraph(getNumGraphs()); //stores graph into temporal value
	}

	//creates MST using Prim's algorithm and stores it
	void constructMST(int startingV){
			
		std::cout << std::endl << "Begin MST starting Vertex " << startingV << std::endl;

		//prims algorithm
		//marks vertex visited
		sV = startingV;
		V[sV] = true;
		D[sV] = 0;
		F[sV] = sV;

		//while there are vertices unvisited
		while (numV < 6) {
			
			//adds found edges to a graph
			if (F[pos] != pos) {
				std::cout << "Add edge " << F[pos] << " to " << pos << std::endl;
				addEdges(F[pos], pos, leastV);
				addEdges(pos, F[pos], leastV);
			}

			leastV = 9999; //initializes least value

			//loops over row and stores all values of edges connected to vertice i
			for (int i = 0; i < 6; i++)
			{
				x = gr[sV][i]; //gets value in graph
				if (x > 0) { // if it exists
					if (V[i] == false) //if is unvisited
					{
						if (D[i] > x) //if is smaller than previous value stored
						{
							D[i] = x; // saves weight
							F[i] = sV; //saves vertice that changed the weight
						}
					}
				}
			}


			//loops over stored weight and finds least unvisited weight
			for (int i = 0; i < 6; i++)
			{
				x = D[i]; 
				if (V[i] == false) // if unvisited
				{
					if (leastV > x) { //if is less than the least value
						leastV = x; //stores value
						pos = i; //stores position
					}
				}
			}



			V[pos] = true; //marks new position
			sV = pos; // makes position the new starting value

			//checks that position was marked visited
			if (V[pos] == true) {
				numV++; //increments visited vertices
			}
			std::cout << std::endl;
		}

		
		saveGraph(); //saves graph
		printGraph(getNumGraphs()); //prints graph
		
		std::cout << std::endl << "End of MST ! " <<std::endl << std::endl;

	}

	//writes MST graph into a file named by the user
	void wGraph(std::string filename)
	{
		writeGraph(filename,getNumGraphs());
	}
	
	
private:
	int D[6]; // least weight to each vertice
	bool V[6]; // marks whether vertice was visited
	int F[6]; // stores last vertice that changed currents vertice weight
	std::array<std::array<int, 6>, 6> gr{}; //temp graph
	std::array<std::array<std::array<int, 6>, 6>, 6> filedGr{}; // stores filed graphs
	int sV = 0; //starting vector
	int x = 0, numV = 0, leastV = 9999, pos = 0; //variables
};
