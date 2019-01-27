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
    }

    queue->rear->next = added;
    queue->rear = added;
}

void pop(Queue *queue){
    if(queue->rear == NULL){
        printf("%d\n", -1);
        return;
    }

    QNode *removed = queue->front;
    queue->front = queue->front->next;

    if(queue->front == NULL){
        queue->rear = NULL;
    }

    printf("%d\n", removed->data);
    free(removed);
}

void size(Queue *queue){
    if(queue->rear == NULL){
        printf("%d\n", 0);
        return;
    }

    QNode *head;
    int size = 1;
    //head = (QNode *)malloc(sizeof(QNode));

    head = queue->front;
    while(head->next != NULL){
        size++;
        head = head->next;
    }

    printf("%d\n", size);
    //free(head);
}

void empty(Queue *queue){
    if(queue->rear == NULL){
        printf("%d\n", 1);
    } else {
        printf("%d\n", 0);
    }
}

void front(Queue *queue){
    if(queue->rear == NULL){
        printf("%d\n", -1);
        return;
    }
    printf("%d\n", (queue->front)->data);
}

void back(Queue *queue){
    if(queue->rear == NULL){
        printf("%d\n", -1);
        return;
    }
    printf("%d\n", (queue->rear)->data);
}

