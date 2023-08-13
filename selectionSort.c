#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 10000

void selection_sort(int *arr, int n) {
    int i, j, min, temp;
    for(i=0; i<n-1; i++) {
        min = i;
        for(j=i+1; j<n; j++) {
            if(arr[j] < arr[min]) min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void main() {
    int arr[MAX], n, i;
    double start, end;

    printf("Enter the number of elements[max=%d]: ", MAX); scanf("%d", &n);
    printf("Elements: ");
    for(i=0; i<n; i++) {
        arr[i] = rand()%n;
        printf("%d ", arr[i]);
    }
    printf("\n");

    start = clock();
    selection_sort(arr, n);
    end = clock();
    printf("The sorted array is: ");
    for(i=0; i<n; i++) printf("%d ", arr[i]);
    printf("@ %f ms\n", end - start);
}

