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
		process[i].arrive_time     = rand() % max_arrival_time;
		process[i].processing_time = rand() % max_processing_time;
		process[i].runtime         = 0;
		process[i].completed       = false;
	}

	return process;
};

void ProcessGenerator::setMaxArrivalTime(int num)
{
	ProcessGenerator::max_arrival_time = num;
};

void ProcessGenerator::setMaxProcessingTime(int num)
{
	ProcessGenerator::max_processing_time = num;
};
