//
// Created by Hanry Ham on 2020-03-19.
//

#include<stdio.h>
#include<stdlib.h>

struct tnode{
    int value;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *newNode(int value){
    struct tnode *curr = (struct tnode *) malloc(sizeof(struct tnode));
    curr->value = value;
    curr->left = NULL;
    curr->right = NULL;
    return curr;
}

void inOrder(struct tnode *root){
    if(root){ //root!=NULL
        inOrder(root->left);
        printf("%d ", root->value);
        inOrder(root->right);
    }
}

void preOrder(struct tnode *root){
    if(root){
        printf("%d ", root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct tnode *root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->value);
    }
}

struct tnode *freeAll(struct tnode *root){
    if(root){
        freeAll(root->left);
        freeAll(root->right);
        free(root);
        root = NULL;
    }
    return root;
}

int main(){
    struct tnode *root = newNode(5);
    root->left = newNode(10);
    root->right = newNode(19);
    root->left->right = newNode(8);
    root->left->left = newNode(98);
    inOrder(root);
    puts("");
    preOrder(root);
    puts("");
    postOrder(root);
    root = freeAll(root);
    return 0;
}

