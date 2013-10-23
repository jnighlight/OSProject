// Lottery Scheduling
// Author: Jure Jumalon

#include <algorithm>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <Process.h>
#include <process_generator.h>

using namespace std;

int main(int argc, const char* argv[])
{
	// Setup the output file
	ofstream output;
	output.open("lottery_output.txt");

	// Setup random number generator
	srand(time(NULL));

	// Set the total amount of processes
	int t_proc    = 100;
	int processes = t_proc;

	// Set the number of tickets available
	int tickets = 5000;
	vector<int> ticket(tickets); // number of tickets for process i

	// Create the processes
	ProcessGenerator::setMaxArrivalTime(0); // all processes arrive at the same time
	Process* process = ProcessGenerator::generateProcesses(processes);

	// Assign at least one ticket per process
	for(int i = 0; i < processes; i++)
	{
		// DEBUG
		/*cout << "process[" << process[i].id << "]:";
		cout << "	arrival_time = " << process[i].arrive_time;
		cout << "	processing_time = " << process[i].processing_time << endl;*/

		ticket.at(i) = i;
	}
	//cout << endl; // Break setup output with runtime output

	// Assign the remaining tickets randomly to processes
	for(int i = processes; i < tickets; i++)
	{
		ticket.at(i) = rand() % processes;
	}

	// Print the tickets and the process they are assigned to
	/*for(int i = 0; i < tickets; i++)
	{
		cout << "ticket[" << i << "]: process " << ticket[i] << endl;
	}*/

	// Begin lottery
	int clock = 0;
	int cur_p = 0;
	int cur_t;

	while(processes > 0)
	{
		// Select a random ticket until an uncompleted process is selected
		do
		{
			cur_t = rand() % ticket.size();
			cur_p = ticket[cur_t];

			ticket.erase(ticket.begin() + cur_t); // remove the selected ticket from the list
		}
		while(process[cur_p].completed);

		// Run the process until it finishes
		while(process[cur_p].runtime < process[cur_p].processing_time)
		{
			clock++;
			process[cur_p].runtime++;

			// Increment the wait times for the remaining processes
			for(int i = 0; i < t_proc; i++)
			{
				if(i != cur_p && !process[i].completed)
				{
					process[i].wait_time++;
				}
			}
		}

		// Process completed
		process[cur_p].completed = true;
		process[cur_p].time_completed = clock;
		processes--;

		// DEBUG
		/*cout << "clock: " << clock;
		cout << "	process " << process[cur_p].id << " completed" << endl;*/
	}

	//cout << endl; // Break runtime output with results output

	// Output results
	output << "process\twait_time\ttime_completed" << endl;
	for(int i = 0; i < t_proc; i++)
	{
		cout << left;
		cout << "process[" << i << "]: ";
		cout << "wait_time = " << setw(8) << process[i].wait_time;
		cout << "time_completed = " << process[i].time_completed << endl;

		output << i << "\t"
			   << process[i].wait_time << "\t"
			   << process[i].time_completed << endl;
	}

	output.close();
	delete(process);
}
