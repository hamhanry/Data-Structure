//
// Created by Hanry Ham on 2020-03-25.
//

#include<stdio.h>
#include<stdlib.h>

struct tnode{
    int value;
    struct tnode *next;
}*head = NULL, *tail = NULL;

void pushTail(int value){
    struct tnode *curr = (struct tnode *) malloc(sizeof(struct tnode));
    curr->value = value;
    curr->next = NULL;
    if(head == NULL){
        // Linked is empty
        head = tail = curr;
    }else{
        // linked list has data
        tail->next = curr;
        tail = curr;
    }
}

void pushHead(int value){
    struct tnode *curr = (struct tnode *) malloc(sizeof(struct tnode));
    curr->value = value;
    curr->next = NULL;
    if(head == NULL){
        head = tail = curr;
    }else{
        curr->next = head;
        head = curr;
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
    }
}

void popTail(){
    struct tnode *curr = head;
    if(curr == tail){
        curr = head = tail = NULL;
        free(curr);
    }else{
        while(curr->next != tail){
            curr = curr->next;
        }

        free(tail);
        tail = curr;
        tail->next = NULL;
    }
}

int main(){
//    pushTail(8);
//    pushTail(3);
//    pushTail(28);
//    pushTail(85);
//    pushTail(3);
    pushHead(8);
    pushHead(3);
    pushHead(28);
    pushHead(85);
    pushHead(3);
    viewLL();
    popHead();
    popHead();
    popTail();
    popTail();
    popTail();
    viewLL();
    return 0;
}