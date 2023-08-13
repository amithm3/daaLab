#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int bfs(int mat[MAX][MAX], int n, int start, int* stack) {
    int visited[MAX];
    int queue[MAX];
    int front = -1, rear = -1, top = -1;
    for(int i = 0; i < n; i++) visited[i] = 0;

    queue[++front] = start;
    visited[start] = 1;
    while(front != rear) {
        int v = queue[++rear];
        stack[++top] = v;
        for(int i = 0; i < n; i++) {
            if(mat[v][i] == 1 && visited[i] == 0) {
                queue[++front] = i;
                visited[i] = 1;
            }
        }
    }

    return top;
}

void main() {
    int mat[MAX][MAX] = {
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0}
    };

    int stack[MAX];
    int top = bfs(mat, 5, 0, stack);

    printf("Traversal: start->");
    for(int i = 0; i <= top; i++) printf("%d->", stack[i]);
    printf("end\n");
}
