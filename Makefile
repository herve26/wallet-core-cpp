# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

main: main.o fieldElement.o point.o
	$(CXX) $(CXXFLAGS) -o main main.o fieldElement.o point.o

# The main.o target can be written more simply

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

fieldElement.o: fieldElement.h

point.o: point.h
