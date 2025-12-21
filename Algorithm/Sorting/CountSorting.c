// Count Sort Implementation in C

// Less assume an array of integers and its size are given, let the size is 10...

// Index:-        0 | 1  | 2  | 3  | 4  | 5  | 6  
// Values:-       9 | 1  | 4  | 14 | 4  | 15 | 6  

// Sorted arr:-   1 | 4  | 4  | 6  | 9  | 14 | 15

// It is the fastest algorithm, in this algorithm, the main thing we do is to dynamically alocates a array of length of one greater than max number in the given array, and initialising each element of that array to 0...
// That dynamically alocated array is called count array... here the maximum number is 15


// Algorithm:-

// count array:-  0 | 1  | 2  | 3  | 4  | 5  | 6  | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15           // initialises the array, length = max + 1
// value:-        0 | 0  | 0  | 0  | 0  | 0  | 0  | 0 | 0 | 0 | 0  | 0  | 0  | 0  | 0  | 0            // initialises each element to 0...


// Index:-        0 | 1  | 2  | 3  | 4  | 5  | 6           'i' is at value 9, so the count[9] will increase by 1
// Values:-       9 | 1  | 4  | 14 | 4  | 15 | 6  
//                ^
//                i

// count array:-  0 | 1  | 2  | 3  | 4  | 5  | 6  | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15          
// value:-        0 | 0  | 0  | 0  | 0  | 0  | 0  | 0 | 0 | 1 | 0  | 0  | 0  | 0  | 0  | 0           


// Index:-        0 | 1  | 2  | 3  | 4  | 5  | 6           'i' is at value 1, so the count[1] will increase by 1
// Values:-       9 | 1  | 4  | 14 | 4  | 15 | 6  
//                    ^
//                    i

// count array:-  0 | 1  | 2  | 3  | 4  | 5  | 6  | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15          
// value:-        0 | 1  | 0  | 0  | 0  | 0  | 0  | 0 | 0 | 1 | 0  | 0  | 0  | 0  | 0  | 0           


// Index:-        0 | 1  | 2  | 3  | 4  | 5  | 6           'i' is at value 4, so the count[4] will increase by 1
// Values:-       9 | 1  | 4  | 14 | 4  | 15 | 6  
//                         ^
//                         i

// count array:-  0 | 1  | 2  | 3  | 4  | 5  | 6  | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15          
// value:-        0 | 1  | 0  | 0  | 1  | 0  | 0  | 0 | 0 | 1 | 0  | 0  | 0  | 0  | 0  | 0           


// Index:-        0 | 1  | 2  | 3  | 4  | 5  | 6           'i' is at value 14, so the count[14] will increase by 1
// Values:-       9 | 1  | 4  | 14 | 4  | 15 | 6  
//                              ^
//                              i

// count array:-  0 | 1  | 2  | 3  | 4  | 5  | 6  | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15          
// value:-        0 | 1  | 0  | 0  | 1  | 0  | 0  | 0 | 0 | 1 | 0  | 0  | 0  | 0  | 1  | 0           


// Index:-        0 | 1  | 2  | 3  | 4  | 5  | 6           'i' is at value 4, so the count[4] will increase by 1
// Values:-       9 | 1  | 4  | 14 | 4  | 15 | 6  
//                                   ^
//                                   i

// count array:-  0 | 1  | 2  | 3  | 4  | 5  | 6  | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15          
// value:-        0 | 1  | 0  | 0  | 2  | 0  | 0  | 0 | 0 | 1 | 0  | 0  | 0  | 0  | 1  | 0           


// Index:-        0 | 1  | 2  | 3  | 4  | 5  | 6           'i' is at value 15, so the count[15] will increase by 1
// Values:-       9 | 1  | 4  | 14 | 4  | 15 | 6  
//                                        ^
//                                        i

// count array:-  0 | 1  | 2  | 3  | 4  | 5  | 6  | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15          
// value:-        0 | 1  | 0  | 0  | 2  | 0  | 0  | 0 | 0 | 1 | 0  | 0  | 0  | 0  | 1  | 1           


// Index:-        0 | 1  | 2  | 3  | 4  | 5  | 6           'i' is at value 6, so the count[6] will increase by 1
// Values:-       9 | 1  | 4  | 14 | 4  | 15 | 6  
//                                             ^
//                                             i

// count array:-  0 | 1  | 2  | 3  | 4  | 5  | 6  | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15          
// value:-        0 | 1  | 0  | 0  | 2  | 0  | 1  | 0 | 0 | 1 | 0  | 0  | 0  | 0  | 1  | 1           

// Now iterating through the count array, and rewrites the original array...
// in count array, important elements are those which have value greater than 0...

// first index 1 value 1  --> original array [0] = 1
// second index 4 value 2 --> original array [1] = 4 ; original array [2] = 4
// third index 6 value 1  --> original array [3] = 6 
// fourth index 9 value 1 --> original array [4] = 9 
// fourth index 14 value 1 --> original array [5] = 14 
// fourth index 15 value 1 --> original array [6] = 15 

// so the original array becomes:- 1 4 4 6 9 14 15 ... ezzzzz

// THE REAL ALGORITHM:- 
// 1> Find the maximum (and minimum, if needed) element in the array
// 2> Create a count array of size (max + 1) and initialize all values to 0
// 3> Traverse the original array and increment count[value] for each element
// 4> Place each element at its correct position in the original array by iterating the count array
// 5> Decrement the count of the placed element until it becomes 0


// O(n + m) time complexity, where n is the number of elements and m is the maximum number in the array...
// Space Complexity is O(k) due to the count array...
// Counting Sort is a stable sort (when implemented with cumulative count)...
// It is not an in-place sorting algorithm...
// It is not a recursive algorithm...
// It is not adaptive in nature...





#include<stdio.h>
#include<stdlib.h>
#include<limits.h> // for int max or int min

void printArray(int *A, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int maximum(int A[], int n){
    int max = INT_MIN;
    for (int i = 0; i < n; i++){
        if (max < A[i]){
            max = A[i];
        }
    }
    return max;
}

void countSort(int *arr, int size){
    // Find the maximum element in A
    int max = maximum(arr, size);

    int * count = (int *)calloc(max+1, sizeof(int));

    for (int i = 0; i < size; i++){
        count[arr[i]]++;
    }

    int i = 0;
    int j = 0;
    while (i <= max){
        if (count[i]>0){
            arr[j++] = i;
            count[i]--;
        } else {
            i++;
        }
    }
    free(count);
}

int main() {
    int arr[]={9, 1, 4, 14, 4, 15, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, size);
    countSort(arr, size);
    printArray(arr, size);
    
    return 0;
}
