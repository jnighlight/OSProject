#ifndef PROCESS_H
#define PROCESS_H

struct Process
{
	int runtime;
	int deadline;
	int priority;
	int arrive_time;
	int wait_time;
	int processing_time;
};

#endif
