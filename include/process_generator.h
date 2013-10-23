#ifndef PROCESS_GENERATOR_H
#define PROCESS_GENERATOR_H

#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <Process.h>

class ProcessGenerator
{
private:
	static int max_arrival_time;
	static int max_processing_time;
public:
	static Process* generateProcesses(int num);
	static void setMaxArrivalTime(int num);
	static void setMaxProcessingTime(int num);
};

#endif
