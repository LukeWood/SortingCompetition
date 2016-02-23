#include "SortingCompetition.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
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
		//testing git
	}

	std::ifstream in(fname.c_str());
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

//RETURN TYPES:
//positive: word1 comes first
//negative: word2 comes first
//zero: equality
inline int SortingCompetition::compareWords(const string& word1, const string& word2)
{
	if(word1.size() < word2.size())
	{
		return 1;
	}
	if(word2.size() < word1.size())
	{
		return -1;
	}
	//TODO This very well may be wrong, we might need -strcmp().
	return strcmp(word1.c_str(),word2.c_str());
}

void SortingCompetition::deleteWords()
{
	delete[] words;
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
