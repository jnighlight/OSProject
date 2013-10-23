#ifndef PROCESS_H
#define PROCESS_H

struct Process
{
	int id;
	int runtime;
	int arrive_time;
	int wait_time;
	int processing_time;
	int deadline;
	int period;
	int priority;

	bool completed;
};

#endif
