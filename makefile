CC = g++
IDIR = ./include/
ODIR = obj/
SDIR = src/
BDIR = build/
CFLAGS = -I$(IDIR)
DEPS = Process.h

fcfs : $(ODIR)FCFSProcessor.o
	$(CC) -o $(BDIR)fcfs $(ODIR)FCFSProcessor.o $(CFLAGS) 
	
$(ODIR)FCFSProcessor.o : $(SDIR)FCFS/FCFSProcessor.cpp ./include/Process.h 
	$(CC) -c -o $(ODIR)FCFSProcessor.o $(SDIR)FCFS/FCFSProcessor.cpp $(CFLAGS)

round_robin : $(ODIR)round_robin.o
	$(CC) -o $(BDIR)round_robin $(ODIR)round_robin.o $(CFLAGS) 
	
$(ODIR)round_robin.o : $(SDIR)Round\ Robin/main.cpp ./include/Process.h 
	$(CC) -c -o $(ODIR)round_robin.o $(SDIR)Round\ Robin/main.cpp $(CFLAGS)
	
edf : $(ODIR)EDF.o
	$(CC) -o $(BDIR)edf $(ODIR)EDF.o $(CFLAGS) 
	
$(ODIR)EDF.o : $(SDIR)EarliestDeadFirst/EDF.cpp ./include/Process.h 
	$(CC) -c -o $(ODIR)EDF.o $(SDIR)EarliestDeadFirst/EDF.cpp $(CFLAGS)