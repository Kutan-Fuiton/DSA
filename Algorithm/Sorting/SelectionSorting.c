// Selection Sort Implementation in C

// Less assume an array of integers and its size are given, let the size is 5...

// Index:-        0 | 1 | 2 | 3 | 4  
// Values:-       8 | 0 | 7 | 1 | 3 

// Sorted arr:-   0 | 1 | 3 | 7 | 8

// In this algorithm, there is a line which divides the sorted part of the array and unsorted part of the array...
// In this algorithm, we will swap ith element and min element on the right of the ith element...

// Algorithm:-
// Index:-        0 | 1 | 2 | 3 | 4

// Pass 1:-       8 | 0 | 7 | 1 | 3       => We will check on 0th index, that is there any number in the array which is less than the number on
//                0 | 8 | 7 | 1 | 3          0th index (which is 8, here!), 8 > 0 (min = 0), 0 < 7 (min = 0), 0 < 1 (min = 0), 0 < 3 (min = 0), 
//         Sorted <-|-> Not sorted yet       so 0th index element and min element will get swaped... 8 <-> 0 will swap

// Pass 2:-       0 | 8 | 7 | 1 | 3            => We will check on 1th index, that is there any number in the array which is < the number on 1th
//                0 | 1 | 7 | 8 | 3               index (which is 8, here!), 8 > 7 (min = 7), 7 > 1 (min = 1), 1 < 3 (min = 1) 
//             Sorted <-|-> Not sorted yet        so 1th index element and min element will get swaped... 8 <-> 1 will swap

// Pass 3:-       0 | 8 | 7 | 1 | 3            => We will check on 2th index, that is there any number in the array which is < the number on 2th
//                0 | 1 | 3 | 8 | 7               index (which is 7, here!), 7 < 8 (min = 7), 7 > 3 (min = 3)
//             Sorted <-|-> Not sorted yet        so 2th index element and min element will get swaped... 7 <-> 3 will swap

// Pass 4:-       0 | 8 | 7 | 1 | 3            => We will check on 3th index, that is there any number in the array which is < the number on 3th
//                0 | 1 | 3 | 8 | 7               index (which is 8, here!), 8 < 7 (min = 7)
//             Sorted <-|-> Not sorted yet        so 3th index element and min element will get swaped... 8 <-> 7 will swap

// After all these passes, the array is sorted...

// we need n-1 passes to sort n elements... and in each pass, we need to do comparisons for n-i-1 times(max) where i is the current pass number...
// So there are total 1 + 2 + 3 + ... + (n-1) = n(n-1)/2 comparisons in total... which is O(n^2) time complexity... best case is O(n) when the array is already sorted...
// Selection Sort is not a stable sort... For example,{7,7',1,9}=>{1,7,7',9} Here 7 and 7' could not maintain their relative position...
// Space Complexity is O(1) as we are not using any extra space except some variables...
// It is an in-place sorting algorithm...
// It is not a recursive algorithm...
// It is not an adaptive algorithm...


#include<stdio.h>

void printArray(int *A, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int n){
    int indexOfMin;
    printf("Running Selection Sort...\n");
    for (int i = 0; i < n-1; i++){  // loop for n-1 passes
        indexOfMin = i;
        for (int j = i+1; j < n; j++){
            if (A[j] < A[indexOfMin]){
                indexOfMin = j;
            }
        }
        int temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

int main() {
    int A[]={4, 5, 2, 9, 7, 3};
    int n = 6;
    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);
    
    return 0;
}