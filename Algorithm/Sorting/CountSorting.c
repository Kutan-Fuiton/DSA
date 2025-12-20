#include<stdio.h>
#include<stdlib.h>

void printArray(int *A, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void countSort(int *arr, int size){
    
}

int main() {
    int arr[]={9, 1, 4, 15, 4, 15, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, size);
    countSort(arr, size);
    printArray(arr, size);
    
    return 0;
}
