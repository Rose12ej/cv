// MAIN.CPP

#include <iostream>
#include "MST.h"
using namespace std;

int main()
{
	//MST GRAPH 1
	MST M;
	M.rGraph("graph.txt"); //READS GRAPH FROM FILE

	M.constructMST(0); //CREATES MST
	
	M.wGraph("MST_1.txt"); //WRITES INTO A FILE

	//MST GRAPH 2
	MST F;
	F.rGraph("graph.txt");

	F.constructMST(3);

	F.wGraph("MST_2.txt");

	//MST GRAPH 3
	MST R;
	R.rGraph("graph.txt");

	R.constructMST(5);

	R.wGraph("MST_3.txt");
	

	system("pause");
	return 0;
}