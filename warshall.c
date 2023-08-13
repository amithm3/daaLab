#include<stdio.h>
#include<stdlib.h>

#define MAX 100

void warshall(int (*mat)[MAX], int n) {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            if(mat[i][k] == 1) {
                for(int j = 0; j < n; j++) mat[i][j] = mat[i][j] || mat[k][j];
            }
        }
    }
}

void main() {
    int mat[MAX][MAX] = {
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0}
    };

    warshall(mat, 5);
    printf("The transitive closure of the matrix is:\n");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) printf("%d ", mat[i][j]);
        printf("\n");
    }
}
