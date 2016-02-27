#include <iostream>
#include <cstdlib>
#include "sortingcompetition.h"

using namespace std; 

int main(int argc, char** argv)
{
	SortingCompetition sort("test.txt"); 
	cout<<"Reading data\n";
	sort.readData(); 
	cout<<"Data Read\n";
	sort.prepareData(); 
	cout<<"Data prepared\n";
	sort.sortData(); 
	cout<<"Data sorted\n";
	sort.outputData("output.txt"); 
	return 0; 
}
