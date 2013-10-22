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
	int runtimes[10]      = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
	int arrival_times[10] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};

	Process process[processes];
	for(int i = 0; i < processes; i++)
	{
		process[i].id              = i;
		process[i].runtime         = runtimes[i];
		process[i].arrive_time     = arrival_times[i];
		process[i].processing_time = 0;
		process[i].completed       = false;
	}

	// Begin Round Robin
	int clock = 0;
	int runtime = 0;
	int cproc = 0;

	while(processes > 0)
	{
		while(runtime < TIME_QUANTUM &&
				process[cproc].processing_time < process[cproc].runtime)
		{
			runtime++;
			clock++;

			process[cproc].processing_time++;
			/*cout << "process: " << cproc;
			cout << "	processing time: " << process[cproc].processing_time;
			cout << "	runtime: " << process[cproc].runtime << endl;*/
		}

		if(process[cproc].processing_time == process[cproc].runtime)
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

			runtime = 0;
		}
	}
}
