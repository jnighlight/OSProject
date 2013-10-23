#include <process_generator.h>
#include <Process.h>

int ProcessGenerator::max_arrival_time = 100;
int ProcessGenerator::max_processing_time = 1000;

Process* ProcessGenerator::generateProcesses(int num)
{
	srand(time(NULL));

	Process* process = new Process[num];

	for(int i = 0; i < num; i++)
	{
		process[i].id              = i;
		process[i].arrive_time     = rand() % (max_arrival_time + 1);
		process[i].processing_time = rand() % max_processing_time + 1;
		process[i].runtime         = 0;
		process[i].wait_time       = 0;
		process[i].completed       = false;
		process[i].time_completed  = -1;
	}

	return process;
};

void ProcessGenerator::setMaxArrivalTime(int num)
{
	max_arrival_time = num;
};

void ProcessGenerator::setMaxProcessingTime(int num)
{
	max_processing_time = num;
};
