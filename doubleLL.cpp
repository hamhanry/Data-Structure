//
// Created by Hanry Ham on 2020-03-25.
//

#include<stdio.h>
#include<stdlib.h>

struct tnode{
    int value;
    struct tnode *next;
    struct tnode *prev;
}*head = NULL, *tail = NULL;

void pushHead(int value){
    struct tnode *curr = (struct tnode *) malloc(sizeof(struct tnode));
    curr->value = value;
    curr->next = NULL;
    if(head == NULL){
        head = tail = curr;
        head->prev = NULL;
    }else{
        curr->next = head;
        head->prev = curr;
        head = curr;
    }
}

void pushTail(int value){
    struct tnode *curr = (struct tnode *) malloc(sizeof(struct tnode));
    curr->value = value;
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

void viewLL(){
    struct tnode *curr = head;
    while(curr){ //curr != NULL
        printf("%d ", curr->value);
        curr = curr->next;
    }
    puts("");
}

void popHead(){
    struct tnode *curr = head;
    if(curr == tail){
        curr = head = tail = NULL;
        free(curr);
    }else{
        head = head->next;
        free(curr);
        head->prev = NULL;
    }
}

void popTail(){
    struct tnode *curr = tail;
    if(curr == head){
        curr = head = tail = NULL;
    }else{
        tail = tail->prev;
        free(curr);
        tail->next = NULL;
    }
}

int main(){
//    pushHead(8);
//    pushHead(3);
//    pushHead(28);
//    pushHead(85);
//    pushHead(3);
    pushTail(8);
    pushTail(3);
    pushTail(28);
    pushTail(85);
    pushTail(3);
    viewLL();
    popHead();
    popHead();
    popTail();
    popTail();
    popTail();
    viewLL();

    return 0;
}