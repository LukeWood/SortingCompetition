#include <iostream>
#include <cstdlib>
#include "sortingcompetition.h"

using namespace std; 

int main()
{
	cout << "bruh\n";
	SortingCompetition sort("test.txt"); 
	sort.readData(); 
	sort.prepareData(); 
	sort.sortData(); 
	sort.outputData("output.txt"); 
	return 0; 
}
