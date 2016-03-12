#include <iostream>
#include <cstdlib>
#include "sortingcompetition.h"
#include <ctime>

using namespace std; 

int main(int argc, char** argv)
{
	sortingcompetition sort("test.txt"); 
	cout<<"Reading data\n";
	sort.readData(); 
	cout<<"Data Read\n";
	sort.prepareData(); 
	cout<<"Data prepared\n";
	clock_t begin = clock();
	sort.sortData(); 
	clock_t end = clock();
 	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout<<"Data sorted: " << elapsed_secs << " Seconds";
	sort.outputData("output.txt"); 
	return 0; 
}
