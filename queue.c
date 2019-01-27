//
// Created by YUTAEK on 2019-01-27.
//
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

QNode *newNode(int key){
    QNode *temp = (QNode *)malloc(sizeof(QNode));
    temp->data = key;
    temp->next = NULL;
    return temp;
}

Queue *createQueue(){
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void push(Queue *queue, int key){
    QNode *added = newNode(key);

    if(queue->rear == NULL){
        queue->front = added;
        queue->rear = added;
    } else {
        queue->rear->next = added;
        queue->rear = added;
    }
}

int pop(Queue *queue){
    int re;

    if(queue->rear == NULL){
        //printf("%d\n", -1);
        return -1;
    }

    QNode *removed = queue->front;
    queue->front = queue->front->next;

    if(queue->front == NULL){
        queue->rear = NULL;
    }

    re = removed->data;
    //printf("%d\n", removed->data);
    free(removed);
    return re;
}

int size(Queue *queue){
    if(queue->rear == NULL){
        //printf("%d\n", 0);
        return 0;
    }

    QNode *head;
    int size = 1;
    //head = (QNode *)malloc(sizeof(QNode));

    head = queue->front;
    while(head->next != NULL){
        size++;
        head = head->next;
    }

    //printf("%d\n", size);
    //free(head);
    return size;
}

int empty(Queue *queue){
    if(queue->rear == NULL){
        //printf("%d\n", 1);
        return 1;
    } else {
        //printf("%d\n", 0);
        return 0;
    }
}

int front(Queue *queue){
    if(queue->rear == NULL){
        //printf("%d\n", -1);
        return -1;
    }
    //printf("%d\n", (queue->front)->data);
    return (queue->front)->data;
}

int back(Queue *queue){
    if(queue->rear == NULL){
        //printf("%d\n", -1);
        return -1;
    }
    //printf("%d\n", (queue->rear)->data);
    return (queue->rear)->data;
}

