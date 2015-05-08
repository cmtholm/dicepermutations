# enables c++11 on CAEN
PATH := /usr/um/gcc-4.7.0/bin:$(PATH)
LD_LIBRARY_PATH := /usr/um/gcc-4.7.0/lib64
LD_RUN_PATH := /usr/um/gcc-4.7.0/lib64

CXXFLAGS := -Wall -pedantic -std=c++11 -g
DEPENDENCIES := $(wildcard .h)
OBJECTS := dice.o diceTest.o

# highest target; sews together all objects into executable
all: dice


clean:
	rm -f *.exe *.o

dice: $(OBJECTS)
	$(CXX) $(OBJECTS) $(CXXFLAGS) -o dice.exe

%.o : $(DEPENDENCIES)
