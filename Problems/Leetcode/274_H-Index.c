#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b){
    return (*(int*)b - *(int*)a);
}

int hIndex(int* citations, int citationsSize) {
    qsort(citations, citationsSize, sizeof(int), cmp);
    int h = 1;
    for (int i = 0; i < citationsSize; i++){
        if (citations[i]>=h){
            h++;
        }
    }
    return h-1;
}

void printArray(int *A, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1,2,2,2,2};
    int size = sizeof(arr)/sizeof(arr[0]);

    // qsort(arr, size, sizeof(int), cmp);
    // printArray(arr, size);

    printf("%d", hIndex(arr, size));
    
    return 0;
}