#ifndef BJVECTOR_H
#define BJVECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct BJImplentationVector {
	int size;
	int capacity;
	int *data;
} BVector;



//Initialize a new vector 
//caller inputs cap and function calculates power of 2 greater than cap 
//and then allocates memory for actual vector and array that the vector holds 
BVector* bvect_new(int cap);

int get_actual_cap(int cap);

void check_exists(void *ptr);

void free_bvect(BVector* vectptr);

int capacity(BVector* vectptr); 

int size(BVector* vectptr);

void push(BVector* vectptr, int number);

void upsize(BVector* vectptr);

void downsize(BVector* vectpty);

bool is_empty(BVector* vectptr);

int at(BVector* vectptr, int index);

void bvect_remove(BVector* vectptr, int index);

void bvect_print(BVector* vectptr);

void run_bjvector_tests();

#endif
