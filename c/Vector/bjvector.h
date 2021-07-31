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

//returns next power of 2 thats atleast double size needed.
int get_actual_cap(int cap);

//exits program if memory was not allocated.
void check_exists(void *ptr);

//frees memory allocated in creation of vector.
void free_bvect(BVector* vectptr);

int capacity(BVector* vectptr); 

//returns number of elements.
int size(BVector* vectptr);

void bvect_push(BVector* vectptr, int number);

//realloc memory cap to double size.
void upsize(BVector* vectptr);

//realloc memory cap to a quarter size.
void downsize(BVector* vectpty);

bool is_empty(BVector* vectptr);

int at(BVector* vectptr, int index);

//delete element at index and shift elements down.
void bvect_delete(BVector* vectptr, int index);

void bvect_print(BVector* vectptr);

void run_bjvector_tests();

//return index if number is found -1 otherwise
int bvect_find(BVector* vectptr, int number);

//removes all numbers matching number.
void bvect_remove_all(BVector* vectptr, int number);

void bvect_insert(BVector* vectptr, int index, int number);

void bvect_prepend(BVector* vectptr, int number);

int bvect_pop(BVector* vectptr);
#endif
