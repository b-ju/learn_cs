#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#ifndef BJ_LINKEDLIST_H
#define BJ_LINKEDLIST_H

// Author: Ben Jurenka
// 8/2/21
//
//Linked List implementation that uses a seperate struct called BList to store the head
// pointer and size of list. I did this to make bounds checking easier and to make
// the code more readable. Although Blist could have been implemented using Node as they
// store the same types of data. The functions use only single pointers to the BList struct
// without having the caller responsible for assignment. 

typedef struct bj_node {
	struct bj_node* next;
	int data; 
} Node;

typedef struct BJ_implement_LinkedList {
	Node* head;
	int size;
} BList;

BList* init_list();

Node* init_node(int value);

int size(BList* list);

int empty(BList* list);

int at(BList* list, int index);

Node* node_at(BList* list, int index);

void push_front(BList* list, int value);

void push_back(BList* list, int value);

//returns data stored in last node
int front(BList* list);

//returns data stored in first node
int back(BList* list);

void print(BList* list);

void check_ob_exists(void* ob);

void free_list(BList* list);

int pop_front(BList* list);

int pop_back(BList* list);

void insert(BList* list, int index, int data);

//erase node at index
void erase(BList* list, int index);

//reverses order of list
void reverse(BList* list);

//removes all nodes with data = value
void remove_val(BList* list, int value);

void run_list_tests();

#endif
