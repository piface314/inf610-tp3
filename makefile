TARGET := inf610-tp3
CC := g++
CCFLAGS := -O2 -Wall -g -std=c++17
LDFLAGS := -Wall -lpthread -lm -ldl -lz -lncurses -rdynamic
PARADIGMS := brute-force exhaustive-search backtrack dynamic-programming greedy
OBJS := $(addprefix obj/,$(addsuffix .o,$(PARADIGMS)))

.PHONY: all clean

all: obj bin bin/$(TARGET)

obj:
	mkdir -p obj

bin:
	mkdir -p bin

bin/$(TARGET): obj/main.o obj/test.o $(OBJS)
	$(CC) -o bin/$(TARGET) obj/* $(LDFLAGS)

obj/main.o: src/main.cpp src/test.hpp
	$(CC) -c $(CCFLAGS) src/main.cpp -o obj/main.o

.SECONDEXPANSION:
obj/%.o: src/$$*.cpp src/$$*.hpp src/utils.hpp src/data.hpp src/test-counter.hpp
	$(CC) -c $(CCFLAGS) src/$*.cpp -o obj/$*.o

obj/test.o: src/test.cpp src/*.hpp src/test.hpp src/test-counter.hpp
	$(CC) -c $(CCFLAGS) src/test.cpp -o obj/test.o

clean:
	rm -vfr obj bin
