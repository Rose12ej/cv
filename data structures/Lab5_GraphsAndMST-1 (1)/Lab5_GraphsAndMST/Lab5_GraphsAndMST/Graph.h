#pragma once


//libraries
#include <memory>
#include <vector>
#include <fstream>
#include "MST.h"
#include <iostream>
#include <algorithm>
#include <array>
#include <assert.h>
#include <assert.h>

//Graph

class Graph
{
public:

	//automatically creates a 6X6 graph
	Graph() {

		//initializing variables
		numI = 0;
		
		//initializing graph
		init();
	
	}

	~Graph() {
		
	}
	//initialize graph
	void init()
	{
		edges = std::make_unique<int[]>(10);

		numEdges = 0;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				graph[i][j] = 0;
			}
		}

	}
	

	//sets edges // copied from the ppt
	void addEdges(int v1, int v2, int wt) {
		if (wt > 0) {
			graph[v1][v2] = wt;
			numEdges++;
		}

	}

	//gets number of vertices
	int getNumVertices() { return vertices; }

	//gets number of edges
	int getNumEdges() { return numEdges; }

	//gets number of edges
	int getNumGraphs() { return numI-1; }

	// reading graph from a file 
	void readGraph(std::string filename) {
		
		fin.open(filename);
		int x = 0;
		
		//read graph
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				fin >> x;
				addEdges(i, j, x);
			}
		}

		//store graph
		edges[numI] = numEdges;
		filedGraph[numI] = graph;

		//print graph

			//print # vertices and # edges
		std::cout << "Number of vertices: " << getNumVertices() << std::endl;
		std::cout << "Number of edges: " << getNumEdges()/2 << std::endl;
		printGraph(numI);
		
		//closing statements
		numI++;
		init();
		fin.close();
	}

	//write an existing graph to a file
	void writeGraph(std::string filename, int pos) {
	
		graph = filedGraph[pos];
		fout.open(filename);
		int x = 0;

		//read graph
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				x = graph[i][j];
				addEdges(i, j, x);
				fout << graph[i][j];
				fout << " ";
			}
			fout << std::endl;
		}

		//store graph
		edges[numI] = numEdges;
		filedGraph[numI] = graph;

		//closing statements
		numI++;
		init();
		fout.close();
	}

	//prints to terminal
	void printGraph(int pos){

		graph = filedGraph[pos];


		//print graph
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				std::cout << graph[i][j] << " ";
			}
			std::cout << std::endl;
		}
	
	}
	
	//gets the asked graph stored
	std::array<std::array<int,6>,6> getGraph(int pos)
	{
		return filedGraph[pos];
	}


	//saves current graph
	void saveGraph()
	{
		edges[numI] = numEdges;
		filedGraph[numI] = graph;
		numI++;
		init();
	}

private:

	std::array<std::array<int, 6>, 6> graph{}; //temporal graph
	std::array<std::array<std::array<int, 6>, 6>, 6> filedGraph{}; // array that stores created graph
	int numEdges, numI; //number of edges, number of graphs
	std::ifstream fin; //input
	std::ofstream fout; //output
	int vertices = 6; //vertices
	std::unique_ptr<int[]> edges; //stores edges in an array

};