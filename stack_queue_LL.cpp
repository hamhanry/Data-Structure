#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct tnode{
	int price;
	char name[25];
	struct tnode *next;
	struct tnode *prev;
}*head = NULL, *tail = NULL;

void push(int price, const char *name){
	struct tnode *curr = (struct tnode *) malloc(sizeof(struct tnode));
	curr-> price = price;
	strcpy(curr->name, name);
	curr->next = NULL;
	if(head == NULL){
		head = tail = curr;
		head->prev = NULL;
	}else{
		tail->next = curr;
		curr->prev = tail;
		tail = curr;
	}
}

//STACK
void popTail(){
	struct tnode *curr = tail;
	if(curr == head){
		head = tail = NULL;	
		free(curr);
	}else if(tail){
		tail = tail->prev;
		free(curr);
		tail->next = NULL;
	}
}

//QUEUE
void popHead(){
	struct tnode *curr = head;
	if(curr == tail){
		head = tail = NULL;
		free(curr);
	}else{
		head = head->next;
		free(curr);
		head->prev = NULL;
	}
}

void view(){
	struct tnode *curr = head;
	while(curr){
		printf("%-20s %-7d\n", curr->name, curr->price);
		curr = curr->next;
	}
	printf("\n\n");
}

int main(){
	push(15000, "Nasi Goreng Ayam");
	push(10000, "Es Jeruk");
	push(20000, "Mie Goreng Spesial");
	push(18000, "Soto Ayam");
	push(13000, "Sate Ayam");
	view();
	
//	popTail();
//	popTail();
//	popTail();
//	popTail();
//	popTail();

	popHead();
	popHead();
	popHead();
	popHead();
	popHead();
	view();
	
	return 0;
}
