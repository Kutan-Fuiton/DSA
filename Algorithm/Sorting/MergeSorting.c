#include<stdio.h>

void printArray(int *A, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void mergeSort(int *arr, int size, ){
        
}

int main() {
    int arr[]={12, 31, 35, 8, 32, 17};
    int size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, size);
    mergeSort(arr, size);
    printArray(arr, size);
    
    return 0;
}