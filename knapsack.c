#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define max(a, b) a > b ? a : b

int* knapsack(int wt[MAX], int pt[MAX], int n, int tw) {
    int bag[MAX][MAX];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= tw; j++) {
            if(i == 0 || j == 0) bag[i][j] = 0;
            else if(wt[i-1] <= j) bag[i][j] = max(pt[i-1] + bag[i-1][j-wt[i-1]], bag[i-1][j]);
            else bag[i][j] = bag[i - 1][j];
        }
    }
    int *pick = (int*)malloc(sizeof(int) * n);
    for(int i = n, j = tw; i > 0; i--) {
        if(bag[i][j] != bag[i-1][j]) {
            pick[i-1] = 1;
            j -= wt[i-1];
        } else pick[i-1] = 0;
    }
    return pick;
}

void main() {
    int wt[MAX] = {1, 5, 3, 4, 4, 2};
    int pt[MAX] = {3, 5, 2, 3, 4, 3};
    int tw = 10;

    int *pick = knapsack(wt, pt, 6, tw);
    for(int i = 0; i < 6; i++) if(pick[i]) printf("%d->%d\t", wt[i], pt[i]);
    printf("\n");
}
