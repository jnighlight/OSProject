#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream myFile;
	string line;
	myFile.open("../Processes.txt");
	if(myFile.is_open())
	{
		while ( getline (myFile,line) )
			{cout << line << endl;}
		myFile.close();
	}
	else
	{
		cout << "Way to suck bro";
	}
	
	return 0;
}