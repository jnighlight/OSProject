// Lottery Scheduling
// Author: Jure Jumalon

#include <algorithm>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <Process.h>
#include <process_generator.h>

#define PROCESSES 10

using namespace std;

int main(int argc, const char* argv[])
{
	// Setup random number generator
	srand(time(NULL));

	// Set the total amount of processess
	int processes = 10;

	// Set the number of tickets available
	int tickets = 50;
	vector<int> ticket(tickets); // number of tickets for process i

	// Create the processes
	ProcessGenerator::setMaxArrivalTime(0); // all processes arrive at the same time
	Process* process = ProcessGenerator::generateProcesses(processes);
	for(int i = 0; i < processes; i++)
	{
		cout << "process[" << process[i].id << "]:";
		cout << "	arrival_time = " << process[i].arrive_time;
		cout << "	processing_time = " << process[i].processing_time << endl;

		// Assign at least one ticket per process
		ticket.at(i) = i;
	}
	cout << endl; // Break setup output with results output

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

			for(int i = 0; i < processes; i++)
			{
				if(i !=)
			}
		}

		// Process completed
		process[cur_p].completed = true;
		process[cur_p].time_completed = clock;
		processes--;

		cout << "clock: " << clock;
		cout << "	process " << process[cur_p].id << " completed" << endl;
	}

	delete(process);
}
