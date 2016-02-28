#include "sortingcompetition.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

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
	if (fname == "")
	{
		std::cout << "Please use a file name.\n";
		return false;
	}

	std::ifstream in(fname.c_str(), ios::in);
	in >> numWords;
	string temp;
	for (int i = 0; i < numWords; i++)
	{
		in >> temp;
		words.push_back(temp);
	}
	in.close();

	return true;
}

bool SortingCompetition::prepareData()
{
int count  = 0; 
	buckets.resize(81);
	for (int x = 0; x < words.size(); x++)
	{
		int size = words[x].size();
		//if (buckets[size].size() == 0)
	//	{
	//		bool exists = false;
	//		for (int x = 0; x < usedBuckets.size(); x++)
	//			if (size == strtol(words[x].c_str(), NULL, 10))
	//				exists = true;
	//		if (!exists)
	//			usedBuckets.push_back(size);
	//	}
		buckets[size].reserve(buckets[size].size() + size);
		wordsCopy.push_back(words[x]); 
		//cout << count++ << "\n"; 
		
	}
	return true;
}

void SortingCompetition::sortData()
{
	for (int i = 0; i < wordsCopy.size(); i++)
	{
		int size = words[i].size();
		buckets[size].push_back(wordsCopy[i]);
	}
	for (int x = 0; x < buckets.size(); x++)
	{
		//selectionSort(usedBuckets[x]);
		quickSort2(x, 0, buckets[x].size()); 
	} 
}

void SortingCompetition::outputData(const string& outputFileName)
{
	ofstream out(outputFileName.c_str());
	for (int i = 1; i < buckets.size(); i++)
	{
		for (int k = 0; k < buckets[i].size(); k++)
		{
			out << buckets[i][k] + '\n'; 
		}
	}
}

void SortingCompetition::selectionSort(int x)
{
	int tracker;
	string temp;

	for (int i = 0; i < buckets[x].size(); i++)
	{
		tracker = i; //make the current index of the unsorted part = to tracker
		for (int j = i + 1; j <buckets[x].size(); j++)
		{
			if (buckets[x][j] < buckets[x][tracker])
				tracker = j;	//tracker will keep track of the index that the bigger value is in
		}
		//if swap is needed 
		if (tracker != i)
		{
			temp = buckets[x][i];
			buckets[x][i] = buckets[x][tracker];
			buckets[x][tracker] = temp;
		}
	}

}
void SortingCompetition::bubbleSort(int x)
{
	string temp;
	for(int i = 0; i < buckets[x].size(); i++)
	{
		for(int j = 0;  j < buckets[x].size()-1; j++)
		{
			if(buckets[x][j] < buckets[x][j+1])
			{
				temp = buckets[x][j+1];
				buckets[x][j+1] = buckets[x][j];
				buckets[x][j] = temp;	
			}
		}
	}
}

void SortingCompetition::quickSort(int x)
{
	if(!(buckets[x].size() >= 3))
	{
		bubbleSort(x);
		return;
	}	
	int medianIndex = findMedian(buckets[x][0],buckets[x][buckets[x].size()/2],buckets[x][buckets[x].size()-1]);
       	if(medianIndex == 1)
	{
		medianIndex = buckets[x].size()/2;
	}
	else if(medianIndex == 2)
	{
		medianIndex = buckets[x].size()-1;
	}
	int i1=0;
	int i2=0;
	string less;
	string greater;

	while(i1 < buckets[x].size())
	{
		//Enter here if the word at i1 is less than the median word
		if(buckets[x][i1] < buckets[x][medianIndex])
		{
			less = buckets[x][i1];
			while(!(buckets[x][i2] > buckets[x][medianIndex]) && i2 < buckets[x].size())
			{
				if(buckets[x][i2] > buckets[x][medianIndex])
				{
					//Swap, however this doesn't guarentee that theyre on the right side of the median.  
					//Maybe I need to put the median directly in the middle of the vector?
					greater = buckets[x][i2];
					buckets[x][i1] = greater;
					buckets[x][i2] = less;
				}
			}
		}
		else if(buckets[x][i1] > buckets[x][medianIndex])
		{
			greater = buckets[x][i1];
		}
		i1++;
	}
	//repeat logn times
}

inline int SortingCompetition::findMedian(const string& first,const string& second,const string& third) const
{
	if((first < second && first > third) || (first > second && first < third))
	{
		return 0;
	}
	else if ((second < first && second > third) || (second < third && second > first))
	{
		return 1;
	}
	else
	{
		return 2;
	}
}


void SortingCompetition::quickSort2(int a, int start, int end) 
{
	int med;
	if (end - start<2) 
		return;
	med = median(a, start, end);
	quickSort2(a, start, med);
	quickSort2(a, med, end);
}
int SortingCompetition::median(int a, int p, int r) 
{
	string x = buckets[a][p];
	string y = buckets[a][(r - p) / 2 + p];
	string z = buckets[a][r - 1];
	
	int i = p - 1; 
	int j = r;
	if (y>x && y<z || y>z && y<x) 
		x = y;
	else if (z>x && z<y || z>y && z<x) 
		x = z;
	while (true) 
	{
		do 
		{ 
			j--;
		} while (buckets[a][j] > x);

		do 
		{ 
			i++;
		} while (buckets[a][i] < x);

		if (i < j)
		{
			string temp = buckets[a][i]; 
			buckets[a][i] = buckets[a][j];
 			buckets[a][j] = temp; 
		}
		else 
{
//cout << count2++; 
return j + 1;
}
	}
}

void SortingCompetition::swap(string &x, string &y)
{

	string temp = x; 
	x = y; 
	y = temp;
}

inline int SortingCompetition::findMedian5(const string& first,const string& second,const string& third,const string& fourth, const string& fifth) const
{
	
	return 0;
}

void SortingCompetition::introSort(int x)
{

}
