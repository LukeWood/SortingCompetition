#include "SortingCompetition.h"
#include <fstream>
#include <iostream>

SortingCompetition::SortingCompetition()
{
	words = NULL;
	fname = NULL;
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
	if(fname == NULL)
	{
		std::cout<<"Please use a file name.\n";
		return false;
	}
	std::ifstream in(fname.c_str());
	string temp;
	if(words)
	{
		deleteWords();
	}
	
	in>>numwords;
	words = new char*[numwords];
	for(int i = 0; i < numwords; i++)
	{
		in>>temp;
		int len = temp.length();
		words[i] = new char[len+1];
		for(int j = 0; j <len; j++)
		{
			words[i][j] = temp[j]; 
		}
		words[i][len] = '\0';
	}
	in.close();

	return true;
}

void SortingCompetition::deleteWords()
{
	for(int i = 0; i < numwords; i++)
	{
		delete[] words[i];
	}
	delete[] words;
}

