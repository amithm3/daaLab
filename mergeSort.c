#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 10000

void merge(int *arr, int low, int high, int mid) {
    int i = low, j = mid + 1, k = low, c[MAX];

    while(i <= mid && j <= high) {
        if(arr[i] < arr[j]) c[k++] = arr[i++];
        else c[k++] = arr[j++];
    }

    while(i <= mid) c[k++] = arr[i++];
    while(j <= high) c[k++] = arr[j++];

    for(i = low; i < k; i++) arr[i] = c[i];
}

void merge_sort(int *arr, int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);

        merge(arr, low, high, mid);
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
    merge_sort(arr, 0, n);
    end = clock();
    printf("The sorted array is: ");
    for(i=0; i<n; i++) printf("%d ", arr[i]);
    printf("@ %f ms\n", end - start);
}
