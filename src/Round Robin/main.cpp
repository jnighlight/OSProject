#include <algorithm>
#include <iostream>
#include <string>
#include <Process.h>

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
		process[i].runtime         = runtimes[i];
		process[i].arrive_time     = arrival_times[i];
		process[i].processing_time = 0;
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
		}

		if(process[cproc].processing_time = process[cproc].runtime)
		{
			cout << "clock: " << clock;
			cout << "	process " << cproc << " completed" << endl;
			processes--;
		}
		else
		{
			cout << "clock: " << clock;
			cout << "	process " << cproc << " switched to " << cproc + 1 % processes << endl;
		}

		cproc = cproc + 1 % processes;
		runtime = 0;
	}
}
