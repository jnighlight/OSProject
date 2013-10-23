#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <Process.h>
#include <process_generator.h>

#define PROCESSES 100

using namespace std;

int clockerSpaniel = 0;

bool processSortByArriveTime(Process procA, Process procB)
{
	return procA.arrive_time <= procB.arrive_time;
}

bool processSortByID(Process procA, Process procB)
{
	return procA.id <= procB.id;
}

bool processSortByDeadline(Process procA, Process procB)
{
	if(procA.completed)
		{return false;}
	if(procB.completed)
		{return true;}
	return procA.deadline <= procB.deadline;
}

int main()
{
	ofstream output;
	output.open("EDF.txt");
	
	ProcessGenerator::setMaxArrivalTime(100);
	ProcessGenerator::setMaxProcessingTime(20);
	Process* procs = ProcessGenerator::generateProcesses(PROCESSES);
	int processesStart = PROCESSES;
	int processesLeft = processesStart;
	
	int missedDead = 0;
	
	bool running = true;
	
	std::sort(procs, procs + processesStart, &processSortByDeadline);
	
	while(processesLeft > 0)
	{		
		//Increment clock
		clockerSpaniel++;
		
		//sort it so the process with the earliest deadline is first in the "queue"
		std::sort(procs, procs + processesStart, &processSortByDeadline);
		
		int nextOK = -1;
		for(int k = 0; k < PROCESSES; k++)
		{
			if(!procs[k].completed && procs[k].arrive_time <= clockerSpaniel)
			{
				nextOK = k;
				k = PROCESSES;
			}
		}
		if(nextOK != -1)
		{
			//If the processing time is less than the amount of time it needs...
			if(procs[nextOK].processing_time - procs[nextOK].runtime > nextOK)
			{
				//...and if it has already arrived, increase how long it has been processing
				if(procs[nextOK].arrive_time <= clockerSpaniel)
					{procs[nextOK].runtime++;}
				//If it hasn't arrived, then none are in the queue, and we're just spinning
			}
			else
			{
				cout << "finished process # " << procs[nextOK].id << endl;
				cout << "clock: " << clockerSpaniel << endl;
				cout << "arrive_time: " << procs[nextOK].arrive_time << endl;
				cout << "processing_time: " << procs[nextOK].processing_time << endl << endl;
				procs[nextOK].wait_time = (clockerSpaniel - procs[nextOK].arrive_time) - procs[nextOK].processing_time;
				procs[nextOK].wait_time = procs[nextOK].wait_time < 0 ? 0 : procs[nextOK].wait_time;
				procs[nextOK].time_completed = clockerSpaniel - procs[nextOK].arrive_time;
				procs[nextOK].processing_time = -1;
				
				missedDead += procs[nextOK].deadline < clockerSpaniel ? 1 : 0;
				
				processesLeft--;
				procs[nextOK].completed = true;
			}
		}
	}
	
	cout << endl;
	
	std::sort(procs, procs + processesStart, &processSortByID);
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

	output << "Missed deadlines : " << missedDead << endl;
	
	output.close();
	delete(procs);
	
	return 0;
}