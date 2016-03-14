#include <iostream>
#include <cstdlib>
#include "sortingcompetition.h"
#include <ctime>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std; 


int main(int argc, char** argv)
{
	ofstream out("quickintrographresults.txt");
	sortingcompetition sort;
        for(int i = 1; i < 11; i++)
	{
		string fname = to_string(i*25000);
		fname+=".txt";
		sort.setFileName(fname);
		out<<to_string(i*25000)<<" ";
		sort.readData();
		sort.prepareData();
		clock_t begin = clock();
		sort.sortData();
		clock_t end = clock();
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		out<<elapsed_secs<<'\n';
	} 
	out.close();
	out.open("quickgraphresults.txt");
        for(int i = 1; i < 11; i++)
	{
		string fname = std::to_string(i*25000);
		fname+=".txt";
		sort.setFileName(fname);
		out<<to_string(i*25000)<<" ";
		sort.readData();
		sort.prepareData();
		clock_t begin = clock();
		sort.soloQuickSort();
		clock_t end = clock();
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		out<<elapsed_secs<<'\n';
	}
	out.close();
	out.open("selectiongraphresults.txt");
        for(int i = 1; i < 11; i++)
	{
		string fname = std::to_string(i*25000);
		fname+=".txt";
		sort.setFileName(fname);
		out<<to_string(i*25000)<<" ";
		sort.readData();
		sort.prepareData();
		clock_t begin = clock();
		sort.selectionSortData();
		clock_t end = clock();
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		out<<elapsed_secs<<'\n';
	} 
	out.close();
	return 0; 
}
