# Makefile for vector implementation
OBJS	= /Users/benjurenka/learn_cs/c/Vector/main.o /Users/benjurenka/learn_cs/c/Vector/bjvector.o
SOURCE	= /Users/benjurenka/learn_cs/c/Vector/main.c /Users/benjurenka/learn_cs/c/Vector/bjvector.c
HEADER	= /Users/benjurenka/learn_cs/c/Vector/bjvector.h
OUT	= implement_bjs_vector
CC	 = gcc
FLAGS	 = -g
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o:/Users/benjurenka/learn_cs/c/Vector/main.c
	$(CC)  $(FLAGS) main.c, 

bjvector.o:/Users/benjurenka/learn_cs/c/Vector/bjvector.c
	$(CC) $(FLAGS) bjvector.c 


clean:
	rm -f $(OBJS) $(OUT)
