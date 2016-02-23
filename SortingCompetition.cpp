#include "SortingCompetition.h"
#include <fstream>
#include <iostream>
#include <string>
using std::string;
SortingCompetition::SortingCompetition()
{
	words = NULL;
	fname = "";
}

//Pretty simple constructor, does exactly what you'd expect.
SortingCompetition::SortingCompetition(const string& inputFileName)
{
	words = NULL;
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

	std::ifstream in(fname.c_str());
	if(words)
	{
		deleteWords();
	}
	
	in>>numwords;
	words = new string[numwords];
	for(int i = 0; i < numwords; i++)
	{
		in>>words[i];
	}
	in.close();

	return true;
}

void SortingCompetition::deleteWords()
{
	delete[] words;
}

