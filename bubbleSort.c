#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 10000

void bubble_sort(int *arr, int n) {
    int i, j, temp;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-1-i; j++) {
            if(arr[j]>arr[j+1]) {
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
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
    bubble_sort(arr, n);
    end = clock();
    printf("The sorted array is: ");
    for(i=0; i<n; i++) printf("%d ", arr[i]);
    printf("@ %f ms\n", end - start);
}
