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
	out<<"x = [";
	for(int i = 0;  i < 9; i++)
	{
		out<<first[i]<<',';
	}
	out<<first[9];
	out<<"];\n";
	out<<"quicky=[";
	for(int i = 0; i < 9; i++)
	{
		out<<second[i]<<',';
	}
	out<<second[9]<<"];\n";
	second.clear();
	
	in.open("quickintro.txt");
	for(int i = 0; i < 10; i++)
	{
		int temp;
		double temp2;
		in>>temp;
		in>>temp2;
		first.push_back(temp);
		second.push_back(temp2);
	}
	in.close();

	out<<"quickintroy=[";
	for(int i = 0; i < 9; i++)
	{
		out<<second[i]<<',';
	}
	out<<second[9]<<"];\n";
	second.clear();

	
	in.open("selection.txt");
	for(int i = 0; i < 10; i++)
	{
		int temp;
		double temp2;
		in>>temp;
		in>>temp2;
		first.push_back(temp);
		second.push_back(temp2);
	}
	in.close();

	out<<"selectiony=[";
	for(int i = 0; i < 9; i++)
	{
		out<<second[i]<<',';
	}
	out<<second[9]<<"];\n";
	second.clear();

	out.close();
	return 0;
}
