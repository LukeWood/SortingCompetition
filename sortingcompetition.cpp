#include "sortingcompetition.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
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
	clearMemory();
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
		string* t = new string(temp);
		words.push_back(t);
	}
	in.close();

	return true;
}

SortingCompetition::~SortingCompetition()
{
	clearMemory();
}

bool SortingCompetition::prepareData()
{	
	int count  = 0; 
	buckets.resize(81);
	for (int x = 0; x < words.size(); x++)
	{
		int size = words[x]->size();
		buckets[size].reserve(buckets[size].capacity() + 1);
		wordsCopy.push_back(words[x]); 
	}
	equalVals.reserve(numWords); 
	return true;
}

void SortingCompetition::sortData()
{
	for (int i = 0; i < wordsCopy.size(); i++)
	{
		int size = words[i]->size();
		buckets[size].push_back(wordsCopy[i]);
	}
	for (int x = 0; x < buckets.size(); x++)
	{
		//selectionSort(x);
		quickSort2(x, 0, buckets[x].size()); 
		//sort(buckets[x].begin(),buckets[x].end()); 
	} 
}

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
inline void SortingCompetition::bubbleSort(int x)
{
	string* temp;
	for(int i = 0; i < buckets[x].size(); i++)
	{
		for(int j = 0;  j < buckets[x].size()-1; j++)
		{
			if(*buckets[x][j] < *buckets[x][j+1])
			{
				temp = buckets[x][j+1];
				buckets[x][j+1] = buckets[x][j];
				buckets[x][j] = temp;	
			}
		}
	}
}

inline void SortingCompetition::quickSort2(int a, int start, int end) 
{

	int med;
	if (end - start<2) 
		return;
	if (end - start <= 15)
        {
        	insertionSort(a, start, end);
        }
	else
	{
		med = median(a, start, end);
		quickSort2(a, start, med);
		quickSort2(a, med, end);
	}
}
string SortingCompetition::isSorted()
{
	ifstream read(outName.c_str(), ios::in);
	string temp;
	string temp2; 
	read >> temp; 
	read >> temp2; 
	string order = "true"; 
	for (int i = 0; i < numWords - 1; i++)
	{
		if (temp < temp2); 
		else
			order = "false"; 
	}
	return order; 
}
inline int SortingCompetition::median(int a, int p, int r) 
{
	string x = *buckets[a][p];
	string y = *buckets[a][(r - p) / 2 + p];
	string z = *buckets[a][r - 1];
	//string y = buckets[a][(r-p) / 4]
	//string z = buckets[a][(r-p) / 2 + p]
	//string a = buckets[a][p]
	//string b = buckets[a][p]
	
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
			i++;
		} while (*buckets[a][i] < x);

		do 
		{ 
			j--;
		} while (*buckets[a][j] > x);


		if (i < j)
		{
			string* temp = buckets[a][i]; 
			buckets[a][i] = buckets[a][j];
 			buckets[a][j] = temp; 
		}
		else 
		{	
			return j + 1;
		}
	}
}

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

inline void SortingCompetition::shellSort(int a,int start, int end)   
{
    int j= start;
    int d = (pow(3.0,j)-1) / 2;


    while(d < ceil(end/3))
    {
        for(int i=d;i<end;i++)
            {
                string tmp = *buckets[a][i];
                int k;
                for(k = i; k >= d && *buckets[a][k-d] < tmp; k -= d)
               		buckets[a][k] = buckets[a][k-d];
                *buckets[a][k] = tmp;
            }
        j++;
        d = (pow(3.0,j)-1) / 2;
    }

}

inline void SortingCompetition::swap(string* &x, string* &y)
{
	string* temp = x; 
	x = y; 
	y = temp;
}

inline int SortingCompetition::findMedian5(const string& first,const string& second,const string& third,const string& fourth, const string& fifth) const
{	
	return 0;
}

inline void SortingCompetition::introSort(int x)
{
//	maxdepth = log2(buckets[x].size());
//	innerIntroSort(x,0,buckets[x].size(),maxdepth);	
}

inline void SortingCompetition::innerIntroSort(int x, int start, int end,int currdepth) 
{
	//This might need to be a different value
//	if(end-start <=2)
//		return;
//	else if(currdepth == 0)
//	{
//		insertionSort(x,start,end);
//	}
//	else
//	{
//		int* med = median(x,start,end);
//		innerIntroSort(x,start,med, currdepth-1);
//		innerIntroSort(x,med,end, currdepth-1);
//	}
}

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
