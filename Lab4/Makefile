#author: Jakub Michalec
#date: 20/10/17
#license: GNU General Public License v3.0

#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.

CC=g++
CPPFLAGS= -std=c++11 -pthread
HFILES=Semaphore.h
CPPFILES=barrier.cpp Semaphore.cpp

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CPPFLAGS) $(DEBUGFLAGS)

ALL: $(HFILES) $(CPPFILES)
	$(CC) -o barrier $(CPPFLAGS) $(CPPFILES) $(DEBUGFLAGS) -Wall

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
