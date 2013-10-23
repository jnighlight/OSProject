#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Process.h"

using namespace std;

int clockerSpaniel = 0;

bool processSortByArriveTime(Process procA, Process procB)
{
	return procA.arrive_time <= procB.arrive_time;
}

bool processSortByDeadline(Process procA, Process procB)
{
	if(procA.arrive_time < clockerSpaniel)
		{return false;}
	if(procB.arrive_time < clockerSpaniel)
		{return true;}
	return procA.deadline <= procB.deadline;
}

int main()
{
	int runtimes[10] = { 2, 1, 3, 4, 5, 6, 7, 8, 9, 10};
	int ids[10] = { 2, 1, 3, 4, 5, 6, 7, 8, 9, 10};
	int processingTimes[10] = { 2, 1, 3, 4, 5, 6, 7, 8, 9, 10};
	int arrivalTimes[10] = { 2, 1, 3, 4, 5, 6, 7, 8, 9, 10};
	int deadlines[10] = { 2, 1, 3, 4, 5, 6, 7, 8, 9, 10};
	int priorities[10] = { 2, 1, 3, 4, 5, 6, 7, 8, 9, 10};
	int processesStart = 10;
	int processesLeft = processesStart;
	int processesToGo = 10;
	
	bool running = true;

	//Process *pproc = new Process[10];
	Process procs[10];
	for(int i = 0; i < 10; i++)
	{
		procs[i].id = ids[i];
		procs[i].runtime = runtimes[i];
		procs[i].processing_time = processingTimes[i];
		procs[i].arrive_time = arrivalTimes[i];
		procs[i].deadline = deadlines[i];
		procs[i].priority = priorities[i];
	}
	
	std::sort(procs, procs + processesStart, &processSortByDeadline);
	
											//Not necessary anymore - int doneRun = 0;
	while(processesLeft > 0)  //processesToGo + processesLeft > 0)
	{		
		//Increment clock
		clockerSpaniel++;
		
		//If the processing time is less than the amount of time it needs...
		if(procs[0].runtime - procs[0].processing_time > 0)
		{
			//...and if it has already arrived, increase how long it has been processing
			if(procs[0].arrive_time >= clockerSpaniel)
				{procs[0].processing_time++;}
			//If it hasn't arrived, then none are in the queue, and we're just spinning
		}
		else
		{
			cout << "finished process # " << procs[[0].id << endl;
			cout << "clock: " << clockerSpaniel << endl;
			cout << "arrive_time: " << procs[0].arrive_time << endl;
			cout << "runtime: " << procs[0].runtime << endl << endl;
			procs[0].wait_time = (clockerSpaniel - procs[0].arrive_time) - procs[0].runtime;
			procs[0].processing_time = clockerSpaniel - procs[0].arrive_time;
			procs[0].runtime = -1;
			
			processesLeft--;
			procs[0].deadline = 32766;
			
			//sort it so the process with the earliest deadline is first in the "queue"
			std::sort(procs, procs + processesStart, &processSortByDeadline);
		}
		//clockerSpaniel++;
	}
	
	cout << endl;
	
	for(int i = 0; i < 10; i++)
	{
		
		cout << endl << "Process Number: " << i+1 << endl;
		cout << procs[i].wait_time  << endl;
		cout << procs[i].processing_time  << endl;
	}
	
	return 0;
}