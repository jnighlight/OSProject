// Round Robin Scheduling
// Author: Jure Jumalon

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <Process.h>
#include <process_generator.h>

#define TIME_QUANTUM 100

using namespace std;

int main(int argc, const char* argv[])
{
	// Setup the output file
	ofstream output;
	output.open("round_robin_output.txt");

	// Set the total amount of processes
	int t_proc    = 100;
	int processes = t_proc;

	// Create the processes
	ProcessGenerator::setMaxArrivalTime(100); // all processes arrive at the same time
	Process* process = ProcessGenerator::generateProcesses(processes);

	// DEBUG
	/*for(int i = 0; i < processes; i++)
	{
		cout << "process[" << process[i].id << "]:";
		cout << "	arrival_time = " << process[i].arrive_time;
		cout << "	processing_time = " << process[i].processing_time << endl;
	}*/

	// Begin Round Robin
	int clock = 0;
	int processing_time = 0;
	int cur_p = 0;
	int process_checked = 0;

	while(processes > 0)
	{
		// If the process has arrived, run it
		if(process[cur_p].arrive_time <= clock)
		{
			while(processing_time < TIME_QUANTUM &&
					process[cur_p].runtime < process[cur_p].processing_time)
			{
				processing_time++;
				clock++;

				process[cur_p].runtime++;
				/*cout << "process: " << cur_p;
				cout << "	processing time: " << process[cur_p].runtime;
				cout << "	processing_time: " << process[cur_p].processing_time << endl;*/

				// Increment the wait times for the remaining processes
				for(int i = 0; i < t_proc; i++)
				{
					if(i != cur_p && !process[i].completed)
					{
						process[i].wait_time++;
					}
				}
			}

			if(process[cur_p].runtime == process[cur_p].processing_time)
			{
				process[cur_p].completed = true;
				process[cur_p].time_completed = clock;
				processes--;

				// DEBUG
				/*cout << "clock: " << clock;
				cout << "	process " << process[cur_p].id << " out of " << processes << " completed" << endl;*/
			}
		}

		// Switch to the next remaining process
		if(processes > 0)
		{
			int prevp = cur_p;
			//cur_p = (cur_p + 1) % processes;

			// Look for the next uncompleted process
			do
			{
				cur_p = (cur_p + 1) % t_proc;
			}
			while(process[cur_p].completed);

			// DEBUG
			/*cout << "clock: " << clock;
			cout << "	process " << process[prevp].id << " switched to " << process[cur_p].id << endl;*/

			// If there are no arrived processes that need to be run, increment the clock
			process_checked++;
			if(process_checked >= t_proc)
			{
				process_checked = 0;
				clock++;
			}

			processing_time = 0;
		}
	}

	// Output results
	output << "process\tarrival_time\twait_time\ttime_completed" << endl;
	for(int i = 0; i < t_proc; i++)
	{
		cout << left;
		cout << "process[" << i << "]: ";
		cout << "arrival_time = " << setw(8) << process[i].arrive_time;
		cout << "wait_time = " << setw(8) << process[i].wait_time;
		cout << "time_completed = " << process[i].time_completed << endl;

		output << i << "\t"
			   << process[i].arrive_time << "\t"
			   << process[i].wait_time << "\t"
			   << process[i].time_completed << endl;
	}

	output.close();
	delete(process);
}
