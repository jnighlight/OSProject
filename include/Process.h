#ifndef PROCESS_H
#define PROCESS_H

struct Process
{
	int runtime;
	int deadline;
	int priority;
	int arriveTime;
	int waitTime;
	int processingTime;
};

#endif
