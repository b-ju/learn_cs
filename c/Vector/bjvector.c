#include "bjvector.h"

const int GROW = 2;
const int SHRINK = 4;
const int MINSZ = 16;

void check_exists(void *ptr){
	if(ptr == NULL){
		printf("Memory not allocated for new data.\n");
		free(ptr);
		exit(1);
	}
}

int calc_cap(int cap){
	int true_cap = MINSZ;	
	if( cap < 1) { exit(1); }
	while(cap > (true_cap / GROW)){
		true_cap *= GROW;
	}
	return true_cap; 
}

//Initialize a new vector 
//caller inputs cap and cal_cap function calculates power of 2 greater than cap 
//and then allocates memory for actual vector and array that the vector holds 
BVector* bvect_new(int cap){
	
	int actual_cap = calc_cap(cap);

	BVector* vect = malloc(sizeof(BVector));
	check_exists(vect);

	vect->size = 0;
	vect->capacity = actual_cap;

	vect->data = malloc(sizeof(int) * actual_cap);
	printf(" actual_cap = %d", actual_cap);
	check_exists(vect->data);
	return vect;
}

void free_bvect(BVector* vectptr){
	free(vectptr->data);
	free(vectptr);
}

int capacity(BVector* vectptr){ 
	return vectptr->capacity;
}

int size(BVector* vectptr){ 
	return vectptr->size;
}

void bvect_push(BVector* vectptr, int number){
	*(vectptr->data + vectptr->size) = number;
	vectptr->size++;
	if(vectptr->size == vectptr->capacity){
		upsize(vectptr);
	}
}

void upsize(BVector* vectptr){
	int* new_data_ptr = realloc(vectptr->data, sizeof(int) * vectptr->capacity * GROW);
	check_exists(new_data_ptr);
	vectptr->data = new_data_ptr;
	vectptr->capacity *= GROW;

}

bool is_empty(BVector* vectptr){
	return vectptr->size == 0;
}

int at(BVector* vectptr, int index){
	if(index >= vectptr->capacity || index >= vectptr->size){
		printf("Out of Range\n");
		exit(EXIT_FAILURE);
	}
	return *(vectptr->data + index);
}


void downsize(BVector* vectptr){
	int newsize;
	if( vectptr->capacity / SHRINK < MINSZ ) {
		newsize = MINSZ;
	} else {
		newsize = vectptr->capacity / SHRINK;
	}

	int* new_data_ptr = realloc(vectptr->data, sizeof(int) * newsize);
	check_exists(new_data_ptr);
	vectptr->data = new_data_ptr;
	vectptr->capacity = newsize;
}

void bvect_delete(BVector* vectptr, int index){
	if( index >= vectptr->size ){
		printf("index out of range\n");	
	} else {
		int* data = vectptr->data + index;
		int* next = data + 1;
		for( int i = index; i < vectptr->size-1; ++i ){
			*data = *next;
			data = next;
		       ++next;
		}	
		--(vectptr->size);
		if( vectptr->capacity / (vectptr->size + 1) >= 4 && vectptr->capacity != MINSZ ){
			downsize(vectptr);	
		}
	}		
}

void bvect_insert(BVector* vectptr, int index, int number){
	if( index > vectptr->size ){
		printf("index out of range\n");
	} else {
		++vectptr->size;
		int* data = vectptr->data + vectptr->size;
		int* prev = data - 1;	
		for( int i = vectptr->size-1; i > index; --i ){
			*data = *prev;
			data = prev;
			--prev;	
		}
		*data = *prev;
		*prev = number;
		if( vectptr->capacity <= vectptr->size ){
			upsize(vectptr);
		}
	}	
}

void bvect_print(BVector* vectptr){
	printf("-------------------------\n");
	printf(" Capacity = %d, Size = %d\n", capacity(vectptr), size(vectptr));

	for(int i = 0; i < vectptr->size; i++){
		printf("Index %d : %d\n", i, at(vectptr, i));
	}

	printf("-------------------------\n");
}

int bvect_find(BVector* vectptr, int number){
	int* data = vectptr->data;
	for(int i = 0; i < vectptr->size; ++i){
		if( *data == number){
			return i;
		}
		++data;
	}		
	return -1;
}

void bvect_remove_all(BVector* vectptr, int number){
	int found = 0;
	found = bvect_find(vectptr, number);
	while(found != -1){
		bvect_delete(vectptr, found); 
		found = bvect_find(vectptr, number);
	}
}


void bvect_prepend(BVector* vectptr, int number){
	bvect_insert(vectptr, 0, number);
}

int bvect_pop(BVector* vectptr){
	int pop_val = at(vectptr, vectptr->size - 1);
	bvect_delete(vectptr, vectptr->size - 1);
	return pop_val;
}

void run_bjvector_tests(){
	BVector* my_vector = bvect_new(3);
	bvect_push(my_vector, 4);
	bvect_push(my_vector, 5);
	bvect_push(my_vector, 5);
	bvect_push(my_vector, 5);
	bvect_push(my_vector, 1);
	
	bvect_print(my_vector);

	int num_vals = 21;
	printf(" bvect_pushing %d  more values...\n", num_vals);
	for(int i = 0; i < num_vals; i++){
		bvect_push(my_vector, i);
	}

	bvect_print(my_vector);

	num_vals = 10;
	printf(" Removing %d from index 4 to %d.\n", num_vals, 3 + num_vals);
	for(int i = num_vals; i > 0; i--){
		bvect_delete(my_vector, 4);
	} 

	bvect_print(my_vector);
	printf(" Popping 3 values...\n");

	bvect_pop(my_vector);
	bvect_pop(my_vector);
	bvect_pop(my_vector);
	bvect_print(my_vector);

	printf(" Inserting 757575 into index 5\n");
	
	bvect_insert(my_vector, 5, 757575);
	bvect_print(my_vector);
	
	printf(" Prepending 42.\n");
	
	bvect_prepend(my_vector, 42);
	bvect_print(my_vector);	

	printf(" Searching for value 999. %d\n", bvect_find(my_vector, 999));
	printf(" Searching for value 42. %d\n", bvect_find(my_vector, 42));
	printf(" Searching for value 10. %d\n", bvect_find(my_vector, 10));
	printf(" Searching for value 17. %d\n", bvect_find(my_vector, 17));

	printf(" Removing all 5s\n");
	bvect_remove_all(my_vector, 5);
	bvect_print(my_vector);

	free_bvect(my_vector);
	printf("END TESTS\n");
}
