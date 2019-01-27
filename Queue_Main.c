#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int main(){
    Queue *queue;
    int operNum;
    char oper[6];
    int data;

    queue = createQueue();

    scanf("%d", &operNum);
    for(int i = 0 ; i < operNum ; i++){
        scanf("%s", &oper);
        if(strncmp(oper, "push", 4) == 0){
            scanf("%d", &data);
            push(queue, data);
        } else if(strncmp(oper, "pop", 3) == 0){
            pop(queue);
        } else if(strncmp(oper, "empty", 5) == 0){
            empty(queue);
        } else if(strncmp(oper, "size", 4) == 0){
            size(queue);
        } else if(strncmp(oper, "front", 5) == 0){
            front(queue);
        } else if(strncmp(oper, "back", 4) == 0){
            back(queue);
        } else {
            printf("명령어를 잘못입력하셨습니다.");
            i--;
        }
    }

    return 0;
}

