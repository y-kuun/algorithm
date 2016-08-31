CC = clang++
CXX_FLAG = -std=c++11 -g

all: main

main.exe: main.o
    $(CC) $(CXX_FLAG) main.o -o $@

main.o: main.cc
    $(CC) $(CXX_FLAG) $^ -o $@

clean:
    rm *.o *.exe