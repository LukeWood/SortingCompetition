#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
	ifstream in;
	ofstream out;
	vector<int> first;
	vector<double> second;
	in.open("quick.txt");
	for(int i = 0; i < 9; i++)
	{
		int temp;
		double temp2;
		in>>temp;
		in>>temp2;
		first.push_back(temp);
		second.push_back(temp2);
	}
	in.close();
	out.open("script.m");
	for(int i = 0; 
	return 0;
}
