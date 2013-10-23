CC = g++
IDIR = ./include/
ODIR = obj/
SDIR = src/
BDIR = build/
CFLAGS = -I$(IDIR)
DEPS = Process.h process_generator.h

fcfs : $(ODIR)FCFSProcessor.o $(ODIR)process_generator.o
	$(CC) -o $(BDIR)fcfs $(ODIR)FCFSProcessor.o $(ODIR)process_generator.o $(CFLAGS) 
	
$(ODIR)FCFSProcessor.o : $(SDIR)FCFS/FCFSProcessor.cpp $(IDIR)Process.h 
	$(CC) -c -o $(ODIR)FCFSProcessor.o $(SDIR)FCFS/FCFSProcessor.cpp $(CFLAGS)
	
$(ODIR)process_generator.o : $(SDIR)process_generator.cpp $(IDIR)process_generator.h $(IDIR)Process.h
	$(CC) -c -o $(ODIR)process_generator.o $(SDIR)process_generator.cpp $(CFLAGS)

round_robin : $(ODIR)round_robin.o $(ODIR)process_generator.o
	$(CC) -o $(BDIR)round_robin $(ODIR)round_robin.o $(CFLAGS) 
	
$(ODIR)round_robin.o : $(SDIR)Round\ Robin/main.cpp $(IDIR)Process.h 
	$(CC) -c -o $(ODIR)round_robin.o $(SDIR)Round\ Robin/main.cpp $(CFLAGS)
	
edf : $(ODIR)EDF.o $(ODIR)process_generator.o
	$(CC) -o $(BDIR)edf $(ODIR)EDF.o $(ODIR)process_generator.o $(CFLAGS) 
	
$(ODIR)EDF.o : $(SDIR)EarliestDeadFirst/EDF.cpp $(IDIR)Process.h 
	$(CC) -c -o $(ODIR)EDF.o $(SDIR)EarliestDeadFirst/EDF.cpp $(CFLAGS)
	
$(ODIR)process_generator.o : $(SDIR)process_generator.cpp $(IDIR)process_generator.h $(IDIR)Process.h
	$(CC) -c -o $(ODIR)process_generator.o $(SDIR)process_generator.cpp $(CFLAGS)

lottery : $(ODIR)lottery.o $(ODIR)process_generator.o
	$(CC) -o $(BDIR)lottery $(ODIR)lottery.o $(ODIR)process_generator.o $(CFLAGS) 
	
$(ODIR)lottery.o : $(SDIR)Lottery/main.cpp $(IDIR)Process.h 
	$(CC) -c -o $(ODIR)lottery.o $(SDIR)Lottery/main.cpp $(CFLAGS)
	
$(ODIR)process_generator.o : $(SDIR)process_generator.cpp $(IDIR)process_generator.h $(IDIR)Process.h
	$(CC) -c -o $(ODIR)process_generator.o $(SDIR)process_generator.cpp $(CFLAGS)