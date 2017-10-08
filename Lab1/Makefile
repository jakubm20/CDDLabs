#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.

CC=g++
CFLAGS= -std=c++11 -pthread
HFILES=Semaphore.h
CFILES=signal.cpp Semaphore.cpp

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
        $(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(HFILES) $(CFILES)
	      $(CC) -o signal $(CFLAGS) $(CFILES) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

#this is customary and just deletes all .o files
CLEAN:
        rm *.o
