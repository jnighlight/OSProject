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
		procs[i].arrive_time = arrivalTimes[i];
	}
	
	std::sort(procs, procs + processesLeft, &processSortByArriveTime);
	
	while(procs[0] != NULL)
	{
		if(procs[i].runtime > 0)
		{
			procs[0].runtime--;
			cout << "The priority is: " << procs[0].priority << endl;
		}
		else
		{
			procs[i].wait_time = clockerSpaniel - procs[i].arriveTime - procs[i].runtime;
			procs[i].processing_time = clockerSpaniel - procs[i].arriveTime;
			
			processesLeft--;
			for(int j = 0; j < processesLeft; j++)
			{
				procs[j] = procs[j+1];
			}
			procs[processesLeft] = NULL;
		}
		clockerSpaniel++;
	}
	
	return 0;
}