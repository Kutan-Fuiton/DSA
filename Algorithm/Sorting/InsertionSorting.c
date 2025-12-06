// Insertion Sort Implementation in C

// Less assume an array of integers and its size are given, let the size is 5...

// Index:-        0 | 1  | 2  | 3  | 4  
// Values:-       7 | 2  | 91 | 77 | 3 

// Sorted arr:-   2 | 3  | 7  | 77 | 91

// In this algorithm, there is a line which divides the sorted part of the array and unsorted part of the array...
// In this algorithm, we take the first element of the unsorted part as key

// Algorithm:-
// Index:-        0 | 1  | 2  | 3  | 4

//         Sorted <-|-> Not sorted yet       => Initially, first element is considered as sorted part and rest as unsorted part...
//                7 | 2  | 91 | 77 | 3    

//              Sorted <-|-> Not sorted yet      => Now, take the first element of unsorted part, which is 2 here, and compare with the last
// Pass 1:-       7 |    | 91 | 77 | 3              element of sorted part, which is 7 here, since 2 < 7, so shift 7 to the right and insert 2 at
//                2 | 7  | 91 | 77 | 3              the starting position...  

//                   Sorted <-|-> Not sorted yet      => Now again, take the first element of unsorted part, which is 91 here, and compare with 
// Pass 2:-       2 | 7  |    | 77 | 3                   the last element of sorted part, which is 7 here, since 91 > 7, no shift will happen... 
//                2 | 7  | 91 | 77 | 3                   91 will be on the position next to 7...

//                        Sorted <-|-> Not sorted yet      => Now again, take the first element of unsorted part, which is 77 here, and compare 
// Pass 3:-       2 | 7  | 91 |    | 3                        with the last element of sorted part, which is 91 here, since 77 < 91, so shift 91 
//                2 | 7  |    | 91 | 3                        to right... 
//                2 | 7  | 77 | 91 | 3                     => again, check that second last element of sorted part, which is 7 here, since 77 > 7,
//                                                            no shift will happen... 77 will be on the position next to 7...

//                            Sorted <-|-> Not sorted yet  => Now again, take the first element of unsorted part, which is 3 here, and compare 
// Pass 4:-       2 | 7  | 77 | 91 |                          with the last element of sorted part, which is 91 here, since 3 < 91, so shift 91 to 
//                2 | 7  | 77 |    | 91                       right...  
//                2 | 7  |    | 77 | 91                    => again, check that second last element of sorted part, which is 77 here, since 3 <   
//                2 |    | 7  | 77 | 91                       77, so shift 77 to right...   
//                2 | 3  | 7  | 77 | 91                    => again, check that third last element of sorted part, which is 7 here, since 3 < 7, 
//                                                            so shift 7 to right... 
//                                                         => again, check that fourth last element of sorted part, which is 2 here, since 3 > 2,
//                                                            no shift happens... 3 will be on the position next to 2...

// After all these passes, the array is sorted...

// we need n-1 passes to sort n elements... and in each pass, we need to do comparisons for i times(max) where i is the current pass number...
// So there are total 1 + 2 + 3 + ... + (n-1) = n(n-1)/2 comparisons in total... which is O(n^2) time complexity... best case is O(n) when the array is already sorted...
// Insertion Sort is a stable sort... For example,{7,6,1,6'}=>{6,7,1,6'}=>{1,6,7,6'}=>{1,6,6',7}=> Here 6 and 6' maintains their relative position...
// Space Complexity is O(1) as we are not using any extra space except some variables...
// It is an in-place sorting algorithm...
// It is not a recursive algorithm...
// It is by defualt adaptive in nature...

#include<stdio.h>

void printArray(int *A, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int *A, int n){
    int key, j;
    for (int i = 1; i <= n-1; i++){    // loop for n-1 passes
        printf("Pass %d\n", i);   // This line is just to show how many passes have been made
        key = A[i]; // setting the key element
        j = i - 1; // gonna compare with previous element, if smaller than the previous element, that key position will assign that previous number and then will go for previous of the previous number by doing j--, and if key became larger, then will assign to the position next to the last compared element.
        while (j>=0 && A[j] > key){   // compare the key(ith element) with (i-1)th element, (i-2)th element,... till 0th element
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;   // finally, place the key at its correct position
    }
}

int main() {
    // int A[]={4, 5, 2, 9, 7, 3};
    int A[]={1, 2, 3, 4, 5, 6};
    int n = sizeof(A)/sizeof(A[0]);
    
    printf("Original arr: ");
    printArray(A, n);

    insertionSort(A, n);
    
    printf("Sorted array: ");
    printArray(A, n);
    
    return 0;
}