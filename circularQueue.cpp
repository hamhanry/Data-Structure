//
// Created by Hanry Ham on 2020-04-05.
//

#include<stdio.h>

#define MAX 5
int queue[MAX];
int head = -1;
int tail = -1;

void push(int value){
    if(head == 0 && tail == MAX-1 || head == tail+1){
        printf("Queue is full\n");
    }else{
        if(head == -1 && tail == -1){
            head = tail = 0;
        }else if(tail == MAX-1 && head != 0){
            tail = 0;
        }else{
            tail++;
        }
        queue[tail] = value;
    }
}

void del(){
    if(head == -1 && tail == -1){
        printf("Queue is empty!\n");
    }else{
        if(head == tail){
            queue[head] = 0;
            head = tail = -1;
        }else{
            queue[head] = 0;
            if(head == MAX-1){
                head = 0;
            }else{
                head++;
            }
        }
    }
}

void view(){
    if(head == -1 && tail == -1){
        printf("Queue is empty!\n");
    }else{
        if(head < tail){
            for(int i = head; i<= tail; i++){
                printf("%d ", queue[i]);
            }
        }else{
            for(int i = 0; i <= tail; i++){
                printf("%d ", queue[i]);
            }
            for(int i = head; i<MAX; i++){
                printf("%d ", queue[i]);
            }
        }
    }
    puts("");
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
//    push(6);
    view();
    del();
    del();
    view();
    push(10);
    view();
    push(15);
    view();
    del();
    view();
    push(20);
    view();
    push(30);
    return 0;
}