//
// Created by YUTAEK on 2019-01-25.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

/*
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

int main() {
    int num_Op;
    int count = 0;
    char oper[6];
    int digit;
    Stack *stack;

    scanf("%d", &num_Op);
    InitStack(&stack);

    for(int i = 0 ; i < num_Op ; i++) {
        scanf("%s", &oper);

        if(strncmp(oper, "push", 4) == 0){
            scanf("%d", &digit);
        }

        if (strncmp(oper, "push", 4) == 0) {
            Push(&stack, digit);
        } else if (strncmp(oper, "pop", 3) == 0) {
            printf("%d\n", Pop(&stack));
        } else if (strncmp(oper, "size", 4) == 0) {
            printf("%d\n", Size(&stack));
        } else if (strncmp(oper, "empty", 5) == 0) {
            printf("%d\n", IsEmpty(&stack));
        } else if (strncmp(oper, "top", 3) == 0) {
            printf("%d\n", Top(&stack));
        }
    }

    return 0;
}
 */

void InitStack(Stack *stack){
    stack->top = NULL;
}

int IsEmpty(Stack *stack){
    return stack->top == NULL;
}

int Size(Stack *stack){
    int size = 0;
    Node *head = stack->top;
    if(IsEmpty(stack)){
        return 0;
    }
    else{
        size = 1;
    }
    while(head->next != NULL){
        size++;
        head = head->next;
    }
    return size;
}

int Top(Stack *stack){
    Node *now;
    int re;
    if(IsEmpty(stack)){
        return -1;
    }
    now = stack->top;
    re = now->data;
    return re;
}

void Push(Stack *stack, int data){
    Node *now = (Node *)malloc(sizeof(Node));
    now->data = data;
    now->next = stack->top;
    stack->top = now;
}

int Pop(Stack *stack){
    Node *now;
    int re;
    if(IsEmpty(stack)){
        return -1;
    }
    now = stack->top;
    re = now->data;

    stack->top = now->next;
    free(now);
    return re;
}




