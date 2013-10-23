// Round Robin Scheduling
// Author: Jure Jumalon

#include <algorithm>
#include <iostream>
#include <string>
#include <Process.h>

#define PROCESSES 10
#define TIME_QUANTUM 100

using namespace std;

int main(int argc, const char* argv[])
{
	// Initialize process values
	int processes = 10;

	// Create the processes
	ProcessGenerator::setMaxArrivalTime(1); // all processes arrive at the same time
	Process* process = ProcessGenerator::generateProcesses(processes);
	for(int i = 0; i < processes; i++)
	{
		cout << "process[" << process[i].id << "]:";
		cout << "	arrival_time = " << process[i].arrive_time;
		cout << "	processing_time = " << process[i].processing_time << endl;
	}

	// Begin Round Robin
	int clock = 0;
	int processing_time = 0;
	int cproc = 0;

	while(processes > 0)
	{
		while(processing_time < TIME_QUANTUM &&
				process[cproc].runtime < process[cproc].processing_time)
		{
			processing_time++;
			clock++;

			process[cproc].runtime++;
			/*cout << "process: " << cproc;
			cout << "	processing time: " << process[cproc].runtime;
			cout << "	processing_time: " << process[cproc].processing_time << endl;*/
		}

		if(process[cproc].runtime == process[cproc].processing_time)
		{
			process[cproc].completed = true;
			processes--;
			cout << "clock: " << clock;
			cout << "	process " << process[cproc].id << " out of " << processes << " completed" << endl;
		}

		// If there are processes remaining, switch to the next process
		if(processes > 0)
		{
			int prevp = cproc;
			//cproc = (cproc + 1) % processes;

			// Look for the next uncompleted process
			do
			{
				cproc = (cproc + 1) % PROCESSES;
			}
			while(process[cproc].completed);

			cout << "clock: " << clock;
			cout << "	process " << process[prevp].id << " switched to " << process[cproc].id << endl;

			processing_time = 0;
		}
	}

	delete(process);
}
