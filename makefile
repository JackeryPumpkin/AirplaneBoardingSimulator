
CC=gcc
CXX=g++

CFLAGS	=   -g -std=c++11

RM=rm

OBJS =	SimulationTester.o Passenger.o Simulator.o OldEngine.o NewEngine.o PrecondViolatedExcep.o

EXES =	Project2

all:	$(EXES)

Project2: $(OBJS)
	$(CXX) $(CFLAGS) -o $@ $^	

	
%.o:	%.cpp %.h %.hpp
	$(CXX) -c $(CFLAGS) $< -o $@
	
clean:
	rm *.exe *.o $(EXES)
