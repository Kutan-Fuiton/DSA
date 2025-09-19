#include<stdio.h>

void printArray(int *A, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void mergeSort(int *A, int *B, int *C, int m, int n){
    int i = 0, j = 0, k = 0;
    while (i<m && j<n){
        if (A[i]>B[j]){
            C[k]=B[j];
            k++;
            j++;
        }
        else {
            C[k]=B[i];
            k++;
            i++;
        }
    }
    while (i<m){
        C[k] = A[i];
        i++;
        k++;
    }
    while (j<n){
        C[k] = A[j];
        j++;
        k++;
    }
}

int main() {
    int A[]={1,2};
    int B[]={6,7,8,9,10};
    int C[20];
    int m = 5;
    int n = 5;
    printArray(A, n);
    printArray(B, n);
    mergeSort(A, B, C, m, n);
    printArray(C, n);
    
    return 0;
}