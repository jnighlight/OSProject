#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <Process.h>
#include <process_generator.h>

#define PROCESSES 100

using namespace std;

bool processSortByArriveTime(Process procA, Process procB)
{
	return procA.arrive_time <= procB.arrive_time;
}

bool processSortByID(Process procA, Process procB)
{
	return procA.id <= procB.id;
}

int main()
{
	ofstream output;
	output.open("FCFS.txt");

	ProcessGenerator::setMaxArrivalTime(100);
	ProcessGenerator::setMaxProcessingTime(10);
	Process* procs = ProcessGenerator::generateProcesses(PROCESSES);
	
	int processesLeft = PROCESSES;
	
	int clockerSpaniel = 0;
	
	std::sort(procs, procs + processesLeft, &processSortByArriveTime);
	
	while(procs[0].processing_time != -1)
	{
		clockerSpaniel++;
		if(procs[0].processing_time - procs[0].runtime > 0)
		{
			if(procs[0].arrive_time <= clockerSpaniel)
				{procs[0].runtime++;}
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
			
			processesLeft--;
			Process holder = procs[0];
			for(int j = 0; j < PROCESSES; j++)
			{
				procs[j] = procs[j+1];
			}
			procs[PROCESSES - 1] = holder;
		}
	}
	
	cout << endl;
	
	std::sort(procs, procs + PROCESSES, &processSortByID);
	
	for(int i = 0; i < PROCESSES; i++)
	{
		
		cout << endl << "Process Number: " << procs[i].id << endl;
		cout << procs[i].wait_time  << endl;
		cout << procs[i].time_completed  << endl;
	}
	
	// Output results
	output << "process\twait_time\ttime_completed" << endl;
	for(int i = 0; i < PROCESSES; i++)
	{
		output << procs[i].id << "\t"
			   << procs[i].wait_time << "\t"
			   << procs[i].time_completed << endl;
	}

	output.close();
	delete(procs);
	
	return 0;
}