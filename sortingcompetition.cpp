/*
Course Number:  <2343>
Programmer:     <Momin Irfan, Luke Wood>
Date:           <03-14-2016>
Program Number: Sorting Competition
Purpose:	Sorts data read from file
Server:			<genuse1>
Instructor:		<Fontenot>
TA:             <Canon>
Sources Consulted: <StackoverFlow,cs.Princeton, drdobbs.com, wikipedia, sotingalgorithms.com, codelab, researchgate, stoimen >
*/

#include "sortingcompetition.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

/** constucts obect with no file name
*/
SortingCompetition::SortingCompetition()
{
	fname = "";
}

/** constucts obect with filename
@param inputFileName name of input file
*/
SortingCompetition::SortingCompetition(const string& inputFileName)
{
	fname = inputFileName;
}

/** cahnges filename
@param inputFileName name of input file
*/
void SortingCompetition::setFileName(const string& inputFileName)
{
	fname = inputFileName;
}

/**Reads data in.
@return whether data read or not
*/
bool SortingCompetition::readData()
{
	for(int i = 0; i < words.size(); i++)
	{
		delete words[i];
	}
	words.clear();  
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
		string* t = new string(temp);
		words.push_back(t);
	}
	in.close();

	return true;
}

/** destructs obects dynamic memory
*/
SortingCompetition::~SortingCompetition()
{
	clearMemory();
}

/** prepares empty data structure to store sorted objects in 
@return whether or not data prepared
*/
bool SortingCompetition::prepareData()
{	 
	wordsCopy.clear(); 
	buckets.clear();
	int count  = 0; 
	buckets.resize(81);
	for (int x = 0; x < words.size(); x++)
	{
		int size = words[x]->size();
		buckets[size].reserve(buckets[size].capacity() + 1); //reserving memory to avoid new calls
		wordsCopy.push_back(words[x]); 
	}
	equalVals.reserve(numWords); 
	return true;
}

/** sorts the data in each bucket 
*/
void SortingCompetition::sortData()
{
	for (int i = 0; i < wordsCopy.size(); i++)
	{
		int size = words[i]->size();
		buckets[size].push_back(wordsCopy[i]); //fill each bucket with the correct value
	}
	for (int x = 0; x < buckets.size(); x++)
	{
		quickSort2(x, 0, buckets[x].size()); //quicksort the elements 
	} 
}

/** outputs sorted data to file
@param outputFileName name of output file
*/
void SortingCompetition::outputData(const string& outputFileName)
{
	outName = outputFileName; 
	ofstream out(outputFileName.c_str());
	for (int i = 1; i < buckets.size(); i++)
	{
		for (int k = 0; k < buckets[i].size(); k++)
		{
			out << *buckets[i][k] + '\n'; 
		}
	}
	out.close(); 
}

/** implementation of selection sort 
@param x where to begin
*/
inline void SortingCompetition::selectionSort(int x)
{
	int tracker;
	string* temp;

	for (int i = 0; i < buckets[x].size(); i++)
	{
		tracker = i; //make the current index of the unsorted part = to tracker
		for (int j = i + 1; j <buckets[x].size(); j++)
		{
			if (*buckets[x][j] < *buckets[x][tracker])
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

/** implementation of bubble sort 
@param x where to begin
*/
inline void SortingCompetition::bubbleSort(int x)
{
	string* temp;
	for(int i = 0; i < buckets[x].size(); i++)
	{
		for(int j = 0;  j < buckets[x].size()-1; j++)
		{
			if(*buckets[x][j] < *buckets[x][j+1]) //if less than, swap
			{
				temp = buckets[x][j+1];
				buckets[x][j+1] = buckets[x][j];
				buckets[x][j] = temp;	
			}
		}
	}
}


/** implementation of quick sort 
@param a bucket being sorted
@param start where to start sorting
@param end where to end sorting
*/
inline void SortingCompetition::quickSort2(int a, int start, int end) 
{

	int med;
	if (end - start<2) //test if done partitioning
		return;
	if (end - start <= 15) //if data set is small move to insertion sort
        {
        	insertionSort(a, start, end);
        }
	else //partition and recurse
	{
		med = median(a, start, end);
		quickSort2(a, start, med);
		quickSort2(a, med, end);
	}
}


/** implementation of median of three and partitioning
@param a bucket being sorted
@param p where to start sorting
@param r where to end sorting
@return postition of pivot
*/
inline int SortingCompetition::median(int a, int p, int r) 
{
	//set key values
	string x = *buckets[a][p]; 
	string y = *buckets[a][(r - p) / 2 + p];
	string z = *buckets[a][r - 1];

	int i = p - 1; 
	int j = r;
	
	//find median
	if (y>x && y<z || y>z && y<x) 
		x = y;
	else if (z>x && z<y || z>y && z<x) 
		x = z;
	
	//find pivot location
	while (true) 
	{
		do 
		{ 
			i++;
		} while (*buckets[a][i] < x); //look for value greater than pivot

		do 
		{ 
			j--;
		} while (*buckets[a][j] > x); //look for value smaller than pivot


		if (i < j) //still searching, swap elements
		{
			string* temp = buckets[a][i]; 
			buckets[a][i] = buckets[a][j];
 			buckets[a][j] = temp; 
		}
		else 
		{	
			return j + 1; //return position of pivot
		}
	}
}

/** implementation of insertion sort 
@param a bucket being sorted
@param start where to start sorting
@param end where to end sorting
*/
inline void SortingCompetition::insertionSort(int a, int start, int end)
{
    for (int x = start + 1; x < end; x++)
    {
        string* val = buckets[a][x];
	int j = x - 1;
        while (j >= 0 && *val < *buckets[a][j])
        {
            buckets[a][j + 1] = buckets[a][j]; 
            j--;
        }
        buckets[a][j + 1] = val;
    }
}

/** implementation of shell sort 
@param a bucket being sorted
@param start where to start sorting
@param end where to end sorting
*/
inline void SortingCompetition::shellSort(int a,int start, int end)   
{
    int j= start;
    int d = (pow(3.0,j)-1) / 2; //Knuths formula for gaps


    while(d < ceil(end/3)) //while still within the given gaps
    {
        for(int i=d;i<end;i++)
            {
                string tmp = *buckets[a][i];
                int k;
                for(k = i; k >= d && *buckets[a][k-d] < tmp; k -= d)
               		buckets[a][k] = buckets[a][k-d];
                *buckets[a][k] = tmp;
            }
        j++; //increment gap
        d = (pow(3.0,j)-1) / 2;
    }

}

/** swaps two values 
@param x string to swap
@param y string to swap
*/
inline void SortingCompetition::swap(string* &x, string* &y)
{
	string* temp = x; 
	x = y; 
	y = temp;
}

/** implementation of introsort 
@param x what bucket needs sorting
*/
inline void SortingCompetition::introSort(int x)
{
	maxdepth = log2(buckets[x].size());
	innerIntroSort(x,0,buckets[x].size(),maxdepth);	
}

/** implementation of introsortsort 
@param x bucket being sorted
@param start where to start sorting
@param end where to end sorting
@param currdepth current depth of sort
*/
inline void SortingCompetition::innerIntroSort(int x, int start, int end,int currdepth) 
{

	if(end-start <=2)
		return;
	else if(currdepth == 0)
	{
		insertionSort(x,start,end);
	}
	else
	{
		int med = median(x,start,end);
		innerIntroSort(x,start,med, currdepth-1);
		innerIntroSort(x,med,end, currdepth-1);
	}
}

/** clearsMemory, rids of dynamic memory
*/
inline void SortingCompetition::clearMemory()
{
	for(int i = 0; i < words.size(); i++)
	{
		delete words[i];
	}
	words.clear(); 
	wordsCopy.clear();
	buckets.clear();	
}
