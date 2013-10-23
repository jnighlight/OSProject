#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Process.h"

using namespace std;

bool processSortByArriveTime(Process procA, Process procB)
{
	return procA.arrive_time <= procB.arrive_time;
}

int main()
{
	int runtimes[10] = { 2, 1, 3, 4, 5, 6, 7, 8, 9, 10};
	int arrivalTimes[10] = { 2, 1, 3, 4, 5, 6, 7, 8, 9, 10};
	int processesLeft = 10;
	
	int clockerSpaniel = 0;
	
	

	//Process *pproc = new Process[10];
	Process procs[10];
	for(int i = 0; i < 10; i++)
	{
		procs[i].runtime = runtimes[i];
		procs[i].arrive_time = arrivalTimes[i];
	}
	
	std::sort(procs, procs + processesLeft, &processSortByArriveTime);
	
	int doneRun = 0;
	while(procs[0].runtime != -1)
	{
		clockerSpaniel++;
		if(procs[0].runtime - doneRun > 0)
		{
			doneRun++;
			//cout << "The arrival time is: " << procs[0].arrive_time << endl;
		}
		else
		{
			cout << "Switching Processes " << endl;
			cout << "clock: " << clockerSpaniel << endl;
			cout << "arrive_time: " << procs[0].arrive_time << endl;
			cout << "runtime: " << procs[0].runtime << endl << endl;
			procs[0].wait_time = (clockerSpaniel - procs[0].arrive_time) - procs[0].runtime;
			procs[0].processing_time = clockerSpaniel - procs[0].arrive_time;
			procs[0].runtime = -1;
			doneRun = 0;
			
			processesLeft--;
			Process holder = procs[0];
			for(int j = 0; j < 10; j++)
			{
				procs[j] = procs[j+1];
			}
			procs[9] = holder;
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