#include "sortingcompetition.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
using std::string;
using namespace std; 
SortingCompetition::SortingCompetition()
{
	fname = "";
}

//Pretty simple constructor, does exactly what you'd expect.
SortingCompetition::SortingCompetition(const string& inputFileName)
{
	fname = inputFileName;
}

//Changes the filename
void SortingCompetition::setFileName(const string& inputFileName)
{
	fname = inputFileName;
}

//Reads data in.
bool SortingCompetition::readData()
{
	//Also im trying to decide if c_strings are a better option or strings, we'll have to see if strcmp is significantly faster than comparing strings
	//There might be some other way to compare strings I kind of forgot.
	if(fname == "")
	{
		std::cout<<"Please use a file name.\n";
		return false;
	}

	std::ifstream in(fname.c_str(), ios::in);
	
	in>>numWords;
	string temp;
	for(int i = 0; i < numWords; i++)
	{
		in>>temp;
		words.push_back(temp);
	}
	in.close();

	return true;
}

bool SortingCompetition::prepareData()
{
	for (int x = 0; x < words.size(); x++)
	{
		wordsCopy.push_back(words[x]); 
	}
}

void SortingCompetition::sortData()
{
	int tracker;
	string temp;

	for (int i=0; i < numWords-1; i++)
	{
		tracker = i; //make the current index of the unsorted part = to tracker
		
		for (int j=i+1; j < numWords; j++)
		{
			if (words[j] < words[tracker])
                  		 tracker=j;	//tracker will keep track of the index that the bigger value is in
		}
		//if swap is needed 
          	if (tracker != i)
            	{
           	      temp = words[i];
           	      words[i] = words[tracker];
           	      words[tracker] = temp;
           	 }
	}
}

void SortingCompetition::outputData(const string& outputFileName)
{
	ofstream out(outputFileName.c_str());
	for(int i = 0; i < numWords; i++)
	{
		out<<wordsCopy[i]<<'\n';		
	}
}

