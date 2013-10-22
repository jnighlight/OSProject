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
	(CC) -c -o $(ODIR)FCFSProcessor.o $(SDIR)FCFS/FCFSProcessor.cpp $(CFLAGS)