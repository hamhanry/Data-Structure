//
// Created by Hanry Ham on 2020-03-19.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tnode{
    char name[100];
    int key;
    struct tnode *next;
};

struct hashPool{
    struct tnode *head;
    struct tnode *tail;
};

const int tableSize = 97;
struct hashPool hashTable[tableSize];

int generateKey(char *name){
    int result = 0;
    int len = strlen(name);
    for(int i=0; i<len; i++){
        result += name[i];
    }
    return result % tableSize;
}

struct tnode *newNode(char *name){
    struct tnode *curr = (struct tnode *) malloc(sizeof(struct tnode));
    strcpy(curr->name, name);
    curr->key = generateKey(name);
    curr->next = NULL;
    return curr;
}

void insert(struct tnode *node){
    if(hashTable[node->key].head == NULL){
        hashTable[node->key].head = hashTable[node->key].tail = node;
    }else{
        hashTable[node->key].tail->next = node;
        hashTable[node->key].tail = node;
    }
}

void printHashChaining(){
    for(int i=0; i<tableSize; i++){
        printf("[%2d] : ", i);
        struct tnode *curr = hashTable[i].head;
        while(curr){
            printf("%-10s ->", curr->name);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

int main(){
    insert(newNode("Hanry"));
    insert(newNode("Hanry"));
    insert(newNode("Budi"));
    insert(newNode("William"));
    insert(newNode("Alfi"));
    insert(newNode("Charlie"));
    printHashChaining();

    return 0;
}