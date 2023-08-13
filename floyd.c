#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define INF 1<<30
#define min(a, b) (a < b ? a : b)

void floyd(int (*mat)[MAX], int n) {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            if(mat[i][k] == INF) continue;
            for(int j = 0; j < n; j++) {
                if(mat[k][j] == INF) continue;
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
}

void main() {
    int mat[MAX][MAX] = {
        {0  ,   3,   8, INF,   4},
        {INF,   0, INF,   1,   7},
        {INF,   4,   0, INF, INF},
        {2  , INF,   5,   0, INF},
        {INF, INF, INF,   6,   0}
    };

    floyd(mat, 5);
    printf("Shortest path matrix:\n");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) printf("%d\t", mat[i][j]);
        printf("\n");
    }
}
