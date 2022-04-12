#COMP = g++
COMP = gcc
#FLAGS = -Wall -g -std=c++0x
FLAGS = -Wall -g

all: paging

mini_project: paging.c
	$(COMP) $(FLAGS) mini_project3.c -lpthread -o $@

clean:
	rm -f paging*.o