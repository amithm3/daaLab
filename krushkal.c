#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define INF 1<<30

int find(int x, int parent[]) {
    while(x != parent[x]) x = parent[x];
    return x;
}

void kruskal(int mat[MAX][MAX], int n) {
    int parent[MAX];
    for(int i = 0; i < n; i++) parent[i] = i;

    int ne = 0, cost = 0;
    while(ne < n-1) {
        int min = INF, u = -1, v = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) if(mat[i][j] < min) {
                min = mat[i][j];
                u = i;
                v = j;
            }
        }

        if(find(u, parent) != find(v, parent)) {
            printf("%d ---> %d = %d\n", u, v, min);
            parent[v] = u;
            cost += min;
            ne++;
        }

        mat[u][v] = mat[v][u] = INF;
    }

    printf("Cost: %d\n", cost);
}

void main() {
    int mat[MAX][MAX] = {
        {  0,   2, INF,   6, INF},
        {  2,   0,   3,   8,   5},
        {INF,   3,   0, INF,   7},
        {  6,   8, INF,   0,   9},
        {INF,   5,   7,   9,   0}
    };
    kruskal(mat, 5);
}
