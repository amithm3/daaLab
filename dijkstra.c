#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define INF 1<<30

int* dijkstra(int mat[MAX][MAX], int n, int s) {
    int* dist = (int*)malloc(n*sizeof(int));
    int visited[MAX];
    for(int i = 0; i<n; i++) {
        dist[i] = mat[s][i];
        visited[i] = 0;
    }
    visited[s] = 1;
    int u, min;
    for(int i = 0; i<n; i++) {
        min = INF;
        for(int j = 0; j<n; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }
        visited[u] = 1;
        for(int j = 0; j<n; j++) {
            if(!visited[j] && dist[j] > dist[u] + mat[u][j]) {
                dist[j] = dist[u] + mat[u][j];
            }
        }
    }
    return dist;
}

void main() {
    int mat[MAX][MAX] = {
        {  0,   2, INF,   6, INF},
        {  2,   0,   3,   8,   5},
        {INF,   3,   0, INF,   7},
        {  6,   8, INF,   0,   9},
        {INF,   5,   7,   9,   0}
    };
    int *dist = dijkstra(mat, 5, 0);
    for(int i = 0; i<5; i++) {
        printf("%d->%d = %d\n", 0, i, dist[i]);
    }
}
