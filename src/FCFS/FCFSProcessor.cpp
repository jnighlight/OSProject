#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <Process.h>
#include <process_generator.h>

#define PROCESSES 50

using namespace std;

bool processSortByArriveTime(Process procA, Process procB)
{
	return procA.arrive_time <= procB.arrive_time;
}

int main()
{
	/*int processing_times[10] = { 2, 1, 3, 4, 5, 6, 7, 8, 9, 10};
	int arrivalTimes[10] = { 2, 1, 3, 4, 5, 6, 70, 8, 9, 10};*/
	ProcessGenerator::setMaxArrivalTime(100);
	ProcessGenerator::setMaxProcessingTime(10);
	Process* procs = ProcessGenerator::generateProcesses(PROCESSES);
	
	int processesLeft = PROCESSES;
	
	int clockerSpaniel = 0;
	
	

	//Process *pproc = new Process[10];
	/*Process procs[PROCESSES];
	for(int i = 0; i < PROCESSES; i++)
	{
		procs[i].id = i+1;
		procs[i].processing_time = processing_times[i];
		procs[i].arrive_time = arrivalTimes[i];
		procs[i].runtime = 0;
	}*/
	
	std::sort(procs, procs + processesLeft, &processSortByArriveTime);
	
	//int doneRun = 0;
	while(procs[0].processing_time != -1)
	{
		clockerSpaniel++;
		if(procs[0].processing_time - procs[0].runtime > 0)
		{
			if(procs[0].arrive_time <= clockerSpaniel)
				{procs[0].runtime++;}
			//cout << "The arrival time is: " << procs[0].arrive_time << endl;
		}
		else
		{
			cout << "Switching Processes from proc # " << procs[0].id <<endl;
			cout << "clock: " << clockerSpaniel << endl;
			cout << "arrive_time: " << procs[0].arrive_time << endl;
			cout << "processing_time: " << procs[0].processing_time << endl << endl;
			procs[0].wait_time = (clockerSpaniel - procs[0].arrive_time) - procs[0].processing_time;
			procs[0].time_completed = clockerSpaniel - procs[0].arrive_time;
			procs[0].processing_time = -1;
			//doneRun = 0;
			
			processesLeft--;
			Process holder = procs[0];
			for(int j = 0; j < PROCESSES; j++)
			{
				procs[j] = procs[j+1];
			}
			procs[PROCESSES - 1] = holder;
		}
		//clockerSpaniel++;
	}
	
	cout << endl;
	
	for(int i = 0; i < PROCESSES; i++)
	{
		
		cout << endl << "Process Number: " << procs[i].id << endl;
		cout << procs[i].wait_time  << endl;
		cout << procs[i].time_completed  << endl;
	}
	
	return 0;
}