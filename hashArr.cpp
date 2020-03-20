//
// Created by Hanry Ham on 2020-03-19.
//

#include<stdio.h>
#include<string.h>

const int tableSize = 27;
char hashTable[tableSize][100];

int generateKey(char *name){ //SMALLCASE
    int result = name[0] - 'a';
    return result;
}

void insert(char* name){
    int idx = generateKey(name);
    strcpy(hashTable[idx],name);
}

void printHashTable(){
    for(int i=0; i<tableSize; i++){
        printf("[%2d] : %s\n", i, hashTable[i]);
    }
}

int main(){
//    printf("%d", generateKey("budi"));
    insert("andi");
    insert("anda");
    insert("budi");
    insert("hanry");
    printHashTable();
    return 0;
}