#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "stack.h"

typedef struct{
    int numOfVertex;
    int **adjacencyMatrix;
} Graph;

Graph *NewGraph(int max_Vertex);
void deleteGraph(Graph *graph);
void AddEdge(Graph *graph, int head_Vertex, int tail_Vertex);
void ViewGraph(Graph *graph);
int edgeDoesExist(Graph *graph, int head_Vertex, int tail_Vertex);
void DFS(Graph *graph, int start_Vertex);
void BFS(Graph *graph, int start_Vertex);

int main(){
    int numOfVertex;
    int numOfEdge;
    int start_Vertex;
    int edge_Index;
    int head_Vertex, tail_Vertex;
    Graph *graph;

    scanf("%d %d %d", &numOfVertex, &numOfEdge, &start_Vertex);

    graph = NewGraph(numOfVertex);

    for(edge_Index = 0 ; edge_Index < numOfEdge ; edge_Index++){
        scanf("%d %d", &head_Vertex, &tail_Vertex);
        AddEdge(graph, head_Vertex, tail_Vertex);
    }

    ViewGraph(graph);
    //DFS(graph, start_Vertex);

    deleteGraph(graph);

    return 0;
}

Graph *NewGraph(int max_Vertex){
    int vertex_Index;

    Graph *graph = (Graph *)malloc(sizeof(Graph)); //그래프 동적할당
    graph->numOfVertex = max_Vertex; //Vertex 개수 초기화
    graph->adjacencyMatrix = (int **)malloc(sizeof(int *) * max_Vertex); //인접행렬 동적할당

    for(vertex_Index = 0 ; vertex_Index < max_Vertex ; vertex_Index++){
        graph->adjacencyMatrix[vertex_Index] = (int *)malloc(sizeof(int) * max_Vertex);
        memset(graph->adjacencyMatrix[vertex_Index], 0, sizeof(int) * max_Vertex); //인접행렬 초기화
    }

    return graph; //그래프 반환
}

void AddEdge(Graph *graph, int head_Vertex, int tail_Vertex){
    graph->adjacencyMatrix[head_Vertex][tail_Vertex] = 1;
    graph->adjacencyMatrix[tail_Vertex][head_Vertex] = 1;
}

void ViewGraph(Graph *graph){
    int head, tail;
    for(head = 0 ; head < graph->numOfVertex ; head++){
        printf("headVertex : %d -> ", head);
        for(tail = 0 ; tail < graph->numOfVertex ; tail++){
            if(graph->adjacencyMatrix[head][tail] == 1){
                printf("%d ", tail);
            }
        }
        printf("\n");
    }
}

void deleteGraph(Graph *graph){
    int vertex_Index;

    for(vertex_Index = 0 ; vertex_Index < graph->numOfVertex ; vertex_Index++){
        free(graph->adjacencyMatrix[vertex_Index]);
    }

    free(graph->adjacencyMatrix);

    free(graph);
}

int edgeDoesExist(Graph *graph, int head_Vertex, int tail_Vertex){
    return graph->adjacencyMatrix[head_Vertex][tail_Vertex];
    //0이면 false, 1이면 true
}

void DFS(Graph *graph, int start_graph){
    int *visited;
    int search;
    Stack *stack;

    visited = (int *)malloc(sizeof(int) * graph->numOfVertex);
    memset(visited, 0, sizeof(int) * graph->numOfVertex);
    InitStack(stack);
    visited[start_graph] = 1;
    Push(stack, start_graph);
    //printf("%d ", start_graph);

    while(!IsEmpty(stack)){
        search = Pop(stack);

    }

    free(visited);
}
