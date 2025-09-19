// 2 5 9 4 7 3
// have to add some key and then compare with previous element, the key will be for checking is at 1, 2, 3, 4, 5 position of the array, so 1 to n-1

// 2 5 9 | 4 7 3 //--> i=3, j = 2
// 2 5 9 | 9 7 3 //--> i=3, j = 1
// 2 5 5 | 9 7 3 //--> i=3, j = 0


#include<stdio.h>

void printArray(int *A, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int *A, int n){
    int key, j;
    for (int i = 1; i <= n-1; i++){
        key = A[i]; // setting the key element
        j = i - 1; // gonna compare with previous element, if smaller than the previous element, that key position will assign that previous number and then will go for previous of the previous number by doing j--, and if key became larger, then will assign to the position next to the last compared element.
        while (j>=0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

int main() {
    int A[]={4, 5, 2, 9, 7, 3};
    int n = 6;
    printArray(A, n);
    insertionSort(A, n);
    printArray(A, n);
    
    return 0;
}