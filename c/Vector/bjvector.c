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

void push(BVector* vectptr, int number){
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

void bvect_remove(BVector* vectptr, int index){
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

void bvect_print(BVector* vectptr){
	printf("-------------------------\n");

	for(int i = 0; i < vectptr->size; i++){
		printf("Index %d : %d\n", i, at(vectptr, i));
	}

	printf("-------------------------\n");
}

void run_bjvector_tests(){
	BVector* my_vector = bvect_new(3);
	push(my_vector, 4);
	push(my_vector, 5);
	push(my_vector, 3);
	push(my_vector, 2);
	push(my_vector, 1);
	
	bvect_print(my_vector);
	printf(" Capacity = %d, Size = %d\n ", capacity(my_vector), size(my_vector));

	int num_vals = 21;

	printf(" Pushing %d  more values...\n", num_vals);

	for(int i = 0; i < num_vals; i++){
		push(my_vector, i);
	}

	bvect_print(my_vector);
	printf(" Capacity = %d, Size = %d\n ", capacity(my_vector), size(my_vector));
	printf(" Removing %d from index 4 to %d.\n", num_vals, 3 + num_vals);

	for(int i = num_vals; i > 0; i--){
		bvect_remove(my_vector, 4);
	} 

	bvect_print(my_vector);

	push(my_vector, 4);
	push(my_vector, 5);
	push(my_vector, 3);
	push(my_vector, 2);
	push(my_vector, 1);

	printf(" Capacity = %d, Size = %d\n ", capacity(my_vector), size(my_vector));
	printf(" Value at index 2 = %d\n", at(my_vector,2));

	free_bvect(my_vector);
	printf("END TESTS\n");
}
