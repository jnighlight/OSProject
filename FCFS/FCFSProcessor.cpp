#include <iostream>
#include <fstream>
#include <string>
#include <Process.h>

using namespace std;

int main()
{
	int runtimes[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int deadlines[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int priorities[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	Process *pproc = new Process[10];
	pproc[0] -> runtime = 10;
	//Process procs[10];
	for(int i = 0; i < 10; i++)
	{
		procs[i]->runtime = runtimes[i];
		procs[i]->deadlines = deadlines[i];
		procs[i]->priorities = priorities[i];
	}
	
	return 0;
}
