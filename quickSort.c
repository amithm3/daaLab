#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 10000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high], i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) swap(&arr[++i], &arr[j]);
    }
    swap(&arr[++i], &arr[high]);
    return i;
}

void quick_sort(int *arr, int low, int high) {
    if(low < high) {
        int pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
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
    quick_sort(arr, 0, n);
    end = clock();
    printf("The sorted array is: ");
    for(i=0; i<n; i++) printf("%d ", arr[i]);
    printf("@ %f ms\n", end - start);
}
