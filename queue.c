//
// Created by caiog on 29/08/2024.
// QUEUE - FIFO

#include <stdio.h>

#define QUEUE_SIZE 10

int queue[QUEUE_SIZE];
int queue_head = 0;
int queue_tail = 0;

void list_elements() {
    printf("======================== \n");
    for (int i = queue_head; i < QUEUE_SIZE; i++) {
        printf("|%d| ", queue[i]);
    }
    printf("======================== \n");
    printf("head = %d \n", queue_head);
    printf("tail = %d \n", queue_tail);
}

void enqueue(const int value) {
    if (queue_tail < QUEUE_SIZE) {
        queue[queue_tail] = value;
        queue_tail++;
        list_elements();
    }else {
        printf("fila está cheia. \n");
    }
}

void dequeue() {
    if (queue_head < queue_tail) {
        queue[queue_head] = 0;
        queue_head++;
    }
    list_elements();
}

void clear() {
    for (int i = 0; i < QUEUE_SIZE; i++) {
        queue[i] = 0;
    }
    queue_head = 0;
    queue_tail = 0;
}

