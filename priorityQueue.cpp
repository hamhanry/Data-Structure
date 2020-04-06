//
// Created by Hanry Ham on 2020-04-05.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tnode{
    char name[25];
    int priority;
    struct tnode *next;
}*head = NULL, *tail = NULL;

void insert(char *name, int priority){
    struct tnode *curr = (struct tnode *) malloc(sizeof(struct tnode));
    strcpy(curr->name, name);
    curr->priority = priority;
    curr->next = NULL;
    if(head == NULL){
        head = tail = curr;
    }else{
        if(priority < head->priority){
            curr->next = head;
            head = curr;
        }else{
            struct tnode *temp = head;
            while(temp->next != NULL && temp->next->priority <= priority){
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
    }
}

void pop(){
    struct tnode *curr = head;
    if(head){
        head = head->next;
        free(curr);
    }
}

void view(){
    struct tnode *curr = head;
    while(curr){
        printf("%d : %s\n", curr->priority, curr->name);
        curr = curr->next;
    }
}

int main(){
    insert("Hanry", 1);
    insert("Budi", 2);
    insert("William", 5);
    insert("Tia", 3);
    insert("Melisa", 4);
    view();
    puts("");
    pop();
    pop();
    view();
    return 0;
}