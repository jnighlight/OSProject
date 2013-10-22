#include <algorithm>
#include <Process.h>

#define TIME_QUANTUM 100

using namespace std;

int main(int argc, const char* argv[])
{
	// Set the number of processes
	int processes = 10;

	// Initialize process values
	int runtimes[processes]      = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
	int arrival_times[processes] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};

	Process proccess[processes];
	for(int i = 0; i < processes; i++)
	{
		proccess[i].runtime         = runtimes[i];
		proccess[i].arrive_time     = arrival_times[i];
		proccess[i].processing_time = 0;
	}

	// Begin Round Robin
	int clock = 0;
	int runtime = 0;
	int current_process = 0;

	while(proccess > 0)
	{
		while(runtime < TIME_QUANTUM)
		{
			runtime++;
			clock++;

			proccess[current_process].processing_time++;
		}

		current_process = current_process + 1 % processes;
		runtime = 0;
	}
}
