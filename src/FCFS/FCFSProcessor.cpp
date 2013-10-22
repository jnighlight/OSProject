#include <iostream>
#include <fstream>
#include <string>
#include "Process.h"

using namespace std;

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
	
	//sort(procs.begin(), procs.end(), &processSortByArriveTime;
	
	/*while(procs[0] != NULL)
	{
		if(procs[i].runtime > 0)
		{
			procs[i].runtime--;
		}
		else
		{
			procs[i].waitTime = clockerSpaniel - procs[i].arriveTime - procs[i].runtime;
			procs[i].processingTime = clockerSpaniel - procs[i].arriveTime;
			
			processesLeft--;
			for(int j = 0; j < processesLeft; j++)
			{
				procs[j] = procs[j+1];
			}
			procs[processesLeft] = NULL;
		}
		clockerSpaniel++;
	}*/
	
	return 0;
}

/*
bool processSortByArriveTime(Process *procA, Process *procB)
{
	return procA.arriveTime <= procB.arriveTime;
}
*/
