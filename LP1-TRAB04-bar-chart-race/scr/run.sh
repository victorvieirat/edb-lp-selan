#! /bin/bash
TARGET=hello-world
CC=g++
FLAGS= -Wall -Werror -fsanitize=address 
OBJS= main.o helloworld.o
all: $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(FLAGS)
 
main.o: src/main.cpp
	$(CC) -c $(FLAGS) src/main.cpp -o main.o
 
helloworld.o: src/helloworld.cpp
	$(CC) -c $(FLAGS) src/helloworld.cpp  -o helloworld.o
 
clean:
	rm -f *.o
