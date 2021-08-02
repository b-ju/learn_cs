#include "bj_linkedlist.h"

BList* init_list(){
	BList* list = malloc(sizeof(BList));
	check_ob_exists(list);
	list->head = NULL;
	list->size = 0;
	return list;
}

Node* init_node(int value){
	Node* node = malloc(sizeof(Node));
	check_ob_exists(node);
	node->next = NULL;
	node->data = value;
	return node;
}

int size(BList* list){
	return list->size;
}

int empty(BList* list){
	return list->size == 0;
}

int at(BList* list, int index){
	if(index >= list->size){
		printf("Index out of range\n");
		return -1;
	}
	Node* cur = list->head;
	for(int i = 0; i < index; ++i){
		cur = cur->next;
	}
	return cur->data;
}

Node* node_at(BList* list, int index){
	if(index >= list->size){
		printf("Index out of range\n");
		return NULL;
	}
	Node* cur = list->head;
	for(int i = 0; i < index; ++i){
		cur = cur->next;
	}
	return cur;
}

void push_front(BList* list, int value){
	Node* front = init_node(value);
	front->next = list->head;
	list->head = front;
	++(list->size);
}

void push_back(BList* list, int value){
	if(list->head == NULL){
		list->head = init_node(value);
		++(list->size);
	} else {
		Node* cur = list->head;
		while(cur->next != NULL){
			cur = cur->next;
		}
		cur->next = init_node(value);
		++(list->size);
	}
}

int front(BList* list){
	if(list->size > 0){
		return list->head->data;
	}
	printf("List empty.\n");
	return 0;
}

int back(BList* list){
	Node* cur = list->head;
	while( cur->next ){
		cur = cur->next;
	}
	return cur->data;
}

void print(BList* list){
	printf("-------------------\n");
	Node* cur = list->head;
	printf(" Size of list: %d\n", list->size);
	while(cur){
		printf(" Current node: %p, data: %d\n",cur,cur->data);
		cur = cur->next;
	}
	printf("-------------------\n");
}

void check_ob_exists(void* ob){
	if(ob == NULL){
		printf("Memory not allocated.\n");
		exit(EXIT_FAILURE);
	}
}

void free_list(BList* list){
	if(list->size == 0){
		free(list);
	 } else { 
		Node* cur = list->head;
		while( cur->next ){
			Node* next = cur->next;
		//	printf("freeing node %p, data: %d\n", cur, cur->data);
			free(cur);
			cur = next;	
		}
//		printf("freeing last node %p, data: %d\n", cur, cur->data);
		free(cur);
//		printf("freeing list %p\n", list);
		free(list);
	}
}	

int pop_front(BList* list){
	if(empty(list)){
		printf("list empty.\n");
		exit(EXIT_FAILURE);
	}
	int data = list->head->data;
	Node* old_head = list->head;
	list->head = list->head->next;
	--(list->size);
	free(old_head);
	return data;
}
	
int pop_back(BList* list){
	if(empty(list)){
		printf("list empty.\n");
		exit(EXIT_FAILURE);
	}
	if(list->size == 1){
		list->size = 0;
		return pop_front(list);
	}
	Node* cur  = list->head;
	Node* last = cur->next; 
	while(last->next){
		cur = last;
		last = last->next;
	}
	cur->next = NULL;	
	printf(" old back: %p, new: %p\n", last, cur);
	int data = last->data;
	--(list->size);
	free(last);
	return data;
}
	
void insert(BList* list, int index, int data){
	if( index >= list->size ){
		printf("inserting at end of list.\n");
		push_back(list, data);
	} else if ( index == 0 ){
		push_front(list,data);
	} else {
		Node* to_insert = init_node(data);
		Node* cur = list->head;
		Node* next = cur->next;
		for(int i = 1; i < index; ++i){
			cur = next;
			next = cur->next;
		}
		cur->next = to_insert;
		to_insert->next = next;
		++(list->size);
	}
}

void erase(BList* list, int index){
	if( index >= list->size ){
		printf("index out of bounds.\n");
		exit(EXIT_FAILURE);
	}
	if( index == 0 ){
		pop_front(list);
	}
	Node* cur = list->head;
	Node* to_del = cur->next;
	Node* after_del = to_del->next;
	for( int i = 1; i < index; ++i){
		cur = to_del;
		to_del = after_del;
		after_del = after_del->next;
	}	
	cur->next = after_del;
	--(list->size);
	free(to_del);
}

void reverse(BList* list){
	Node* prev = NULL;
	Node* cur = list->head;
	Node* next = cur;
	while(cur){
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	list->head = prev;
}

void remove_val(BList* list, int value){
	for(int i = 0; i < list->size; ++i){
		if( at(list, i) == value){
			erase(list, i);
		}
	}
}
void run_list_tests(){
	BList* list = init_list();

	push_back(list, 5);
	push_back(list, 35);
	push_back(list, 55555);
	push_back(list, 105);
	push_back(list, 55555);
	push_back(list, 345);
	push_back(list, 55555);
	push_front(list, 9999);

	print(list);

	printf(" Front: %d\n", front(list));
	printf(" Back: %d\n", back(list));
	printf(" Popping head: %d, head now points to: %p\n", pop_front(list), list->head);

	print(list);

	printf(" Popping tail: %d\n", pop_back(list));
	printf(" Removing all values = 55555\n");
	remove_val(list, 55555);

	print(list);

	printf(" Reversing list.\n");
	reverse(list);

	print(list);

	free_list(list);
}
