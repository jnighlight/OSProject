CC = g++
IDIR = ./include/
ODIR = obj/
SDIR = src/
BDIR = build/
CFLAGS = -I$(IDIR)
DEPS = Process.h

fcfs : $(ODIR)FCFSProcessor.o $(DEPS)
	$(CC) -o $(BDIR)fcfs $(FCFS)FCFSProcessor.o $(CFLAGS) 
	
$(ODIR)FCFSProcessor.o : $(SDIR)FCFS/FCFSProcessor.cpp
	$(CC) -c -o $(ODIR)FCFSProcessor.o $(SDIR)FCFS/FCFSProcessor.cpp $(CFLAGS)
	
$(ODIR)Process.o : $(IDIR)/Process.h
	$(CC) -c -o $(ODIR)Process.o $(IDIR)Process.h $(CFLAGS)