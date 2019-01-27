//
// Created by YUTAEK on 2019-01-27.
//

#ifndef ALGORITHM_QUEUE_H
#define ALGORITHM_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct QNode{
    int data;
    struct QNode *next;
}QNode;

typedef struct Queue{
    QNode *front;
    QNode *rear;
}Queue;

QNode *newNode(int key);
Queue *createQueue();
void push(Queue *queue, int key);
void pop(Queue *queue);
void size(Queue *queue);
void empty(Queue *queue);
void front(Queue *queue);
void back(Queue *queue);

#endif //ALGORITHM_QUEUE_H
