#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Process.h"

using namespace std;

bool processSortByArriveTime(Process procA, Process procB)
{
	return procA.arriveTime <= procB.arriveTime;
}

int main()
{
	int runtimes[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int deadlines[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int priorities[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int arrivalTimes[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int processesLeft = 10;
	
	int clockerSpaniel = 0;
	
	

	//Process *pproc = new Process[10];
	Process procs[10];
	for(int i = 0; i < 10; i++)
	{
		procs[i].runtime = runtimes[i];
		procs[i].deadline = deadlines[i];
		procs[i].priority = priorities[i];
		procs[i].arriveTime = arrivalTimes[i];
	}
	
	std::sort(procs, procs + processesLeft, &processSortByArriveTime);
	
	while(procs[0].runtime != -1)
	{
		if(procs[0].runtime > 0)
		{
			procs[0].runtime--;
			cout << "The priority is: " << procs[0].priority << endl;
		}
		else
		{
			procs[0].waitTime = clockerSpaniel - procs[0].arriveTime - procs[0].runtime;
			procs[0].processingTime = clockerSpaniel - procs[0].arriveTime;
			
			processesLeft--;
			for(int j = 0; j < processesLeft; j++)
			{
				procs[j] = procs[j+1];
			}
			procs[processesLeft].runtime = -1;
		}
		clockerSpaniel++;
	}
	
	return 0;
}