#include "SortingCompetition.h"
#include <fstream>
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
	if(words)
	{
		deleteWords();
	}
	
	in>>numWords;
	words = new string[numWords];
	for(int i = 0; i < numWords; i++)
	{
		in>>words[i];
	}
	in.close();

	return true;
}

void SortingCompetition::deleteWords()
{
	delete[] words;
	words = NULL;
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
			if (words[j].size() < words[tracker].size() && words[j] < words[tracker])
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
