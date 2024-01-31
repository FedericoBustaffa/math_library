
CXX = g++
CXXFLAGS = -Wall -std=c++17 -O2

TARGETS = algebra.x
OBJECTS = main.o

all: $(TARGETS)

algebra.x: $(OBJECTS)
	$(CXX) $^ -o $@

main.o: *.hpp main.cpp

clean:
	-rm -f $(OBJECTS) $(TARGETS)

recompile: clean all

run: algebra.x
	./$^

valrun: algebra.x
	valgrind -s --track-origins=yes ./algebra.x
