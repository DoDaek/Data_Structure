//
// Created by YUTAEK on 2019-01-27.
//

#ifndef ALGORITHM_STACK_H
#define ALGORITHM_STACK_H

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct Stack{
    Node *top;
}Stack;

void InitStack(Stack *stack);
int IsEmpty(Stack *stack);
void Push(Stack *stack, int data);
int Pop(Stack *stack);
int Top(Stack *stack);
int Size(Stack *stack);

#endif //ALGORITHM_STACK_H
