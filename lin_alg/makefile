
CXX = g++
CXXFLAGS = -Wall -std=c++17 -O3 -march=native -pedantic

TARGETS = run.x
OBJECTS = main.o

all: $(TARGETS)

run.x: $(OBJECTS)
	$(CXX) $^ -o $@

main.o: *.hpp main.cpp

clean:
	-rm -f $(OBJECTS) $(TARGETS)

recompile: clean all

run: run.x
	./$^

valrun: run.x
	valgrind -s --track-origins=yes ./run.x
