

//
// Created by caiog on 29/08/2024.
//
#include <stdio.h>

#define STACK_SIZE 10

int stack[STACK_SIZE];
int stack_head = 0;
int stack_tail = 0;

void visualize_stack() {
    printf("======================== \n");
    for (int i = 0; i < stack_tail; i++) {
        printf("|%d| ", stack[i]);
    }
    printf("======================== \n");
    printf("head = %d \n", stack_head);
    printf("tail = %d \n", stack_tail);
}

void push(int item) {
    if (stack_tail < STACK_SIZE) {
        stack[stack_tail] = item;
        stack_tail++;
        visualize_stack();
    } else {
        printf("Stack overflow \n");
    }
}

void pop() {
    if (stack_head == stack_tail) {
        printf("Stack underflow \n");
    } else {
        stack[stack_tail] = 0;
        stack_tail--;
        visualize_stack();
    }
}

void clearStack() {
    for (int i = 0; i < STACK_SIZE; i++) {
        stack[i] = 0;
    }
    stack_head = 0;
    stack_tail = 0;
}