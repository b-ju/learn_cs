# List of files
C_SRCS          = main.c bj_linkedlist.c  
C_OBJS          = main.o bj_linkedlist.o  
C_HEADERS       = /Users/benjurenka/learn_cs/c/LinkedList/bj_linkedlist.h

OBJS            = ${C_OBJS}
EXE             = bj_linkedlist
DEFINES         = -DDEBUG

# Compiler and loader commands and flags
GCC             = gcc
GCC_FLAGS       = -g -std=c11 -Wall -c
LD_FLAGS        = -g -std=c11 -Wall

# Compile .c files to .o files
.c.o:
	$(GCC) $(GCC_FLAGS) $(DEFINES) $<

# Target is the executable
default: $(OBJS)
	$(GCC) $(LD_FLAGS) $(OBJS) -o $(EXE)

# Recompile C objects if headers change
${C_OBJS}:      ${C_HEADERS}

# Clean up the directory
clean:
	rm -f *.o *~ $(EXE)

