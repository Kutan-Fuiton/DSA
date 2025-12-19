#include<stdio.h>
#include<stdlib.h>

void printArray(int *A, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Time Complexity:- O(n)
void merge(int *arr, int start, int mid, int end){
    int * temp = (int *)malloc((end - start + 1) * sizeof(int));
    int size = 0;
    int i = start, j = mid + 1;
    while (i <= mid && j <= end){
        if (arr[i] <= arr[j]) {
            temp[size++] = arr[i];
            i++;
        } else {
            temp[size++] = arr[j];
            j++;
        }
    }
    while (i <= mid){
        temp[size++] = arr[i];
        i++;
    }
    while (j <= end){
        temp[size++] = arr[j];
        j++;
    }

    for (int k = 0; k < size; k++){
        arr[k+start] = temp[k];
    }
}

// Time Complexity:- O(nlogn)
void mergeSort(int *arr, int start, int end){
    // int mid = (start + end)/2;    // this could arise to integer overflow, when the start and will be a big number
    
    if (start < end){
        int mid = start + (end-start)/2;

        mergeSort(arr, start, mid);  // Left array
        mergeSort(arr, mid+1, end);  // Right array

        merge(arr, start, mid, end);
    }

}

int main() {
    int arr[]={12, 31, 35, 8, 32, 17};
    int size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, size);
    mergeSort(arr, 0, size-1);
    printArray(arr, size);
    
    return 0;
}












// Merge Sort Implementation in C

// Less assume an array of integers and its size are given, let the size is 10...

// Index:-        0 | 1  | 2  | 3  | 4  | 5   
// Values:-      12 | 31 | 35 | 8  | 32 | 17

// Sorted arr:-   8 | 12 | 17 | 31 | 32 | 35

// In this algorithm, we will break the array into two halves, and recursively, each halve will also break into two further halves, untill it reached with only 1 element in each halves, and at last every elements will be seperated
// then those one elements halves will merge by sorting, that means, smaller element will go ago than larger element, and will get merged, that's where merge sort acts...
// So its basically, a process of divide and merge sort...
// start -> st;   mid -> md = st + (e-st)/2;    end -> e;

// Algorithm:-

// Index:-        0 | 1  | 2  | 3  | 4  | 5
//               12 | 31 | 35 | 8  | 32 | 17                  At First, start = 0 always, end = size - 1 = 6 - 1 = 5;
//                ^        ^              ^                   By this way, mid = 0 + (5-0)/2 = 2;
//               st        md             e                   the array will get divided into two equal parts (st --> md) & (md+1 --> e)


// Index:-        0 | 1  | 2            3  | 4  | 5
//               12 | 31 | 35           8  | 32 | 17          Second, left: start = 0, end = 2, mid = 1
//                ^   ^    ^            ^    ^    ^                   right: start = 3, end = 4, mid = 5
//               st   md   e            st   md   e           these two arrays will get divided int two halves again
//               st        md             e                   the array will get divided into two equal parts (st --> md) & (md+1 --> e)


// Index:-        0 | 1         2           3  | 4            5
//               12 | 31       35           8  | 32          17          Third, 1st: start = 0, end = 1, mid = 0;  3rd: start = 3, end = 4, mid = 3
//                ^   ^         ^           ^    ^            ^                 2nd: start = 2 = end;        4th: start = 5 = end
//               st   e        st           st   e           st          We can see 4 halves, now we will stop dividing them where start = end 
//               md             e           md                e          Here, we can see 2nd and 4th halves reached that state, hence undivisible


// Index:-     0     1                     3     4     
//            12     31                    8     32              Fourth, 1st: start = 0 = end;        3rd: start = 3 = end
//             ^     ^                     ^     ^                       2nd: start = 1 = end;        4th: start = 4 = end
//            st     st                    st    st              We can see 4 halves, now we will stop dividing them where start = end 
//             e      e                    e     e               Here, we can see all the halves reached that state, hence undivisible


// Now the merge sort process:- Where we will compare the two elements, smaller element will go to left side, and larger element will go to right side


// Index:-     0     1                     3     4     
//            12     31                    8     32              first, i = 0, j = 1       will similarly work for      i = 3, j = 4
//             ^     ^                     ^     ^               a new array will get create, where compare the elements of i and j, element      
//             i     j                     i     j               will get inserted into the new array, and then finally into the original array
//             12 | 31                     8  | 32

// Index:-        0 | 1         2           3  | 4            5
//               12 | 31       35           8  | 32          17          second, i = 0, j = 2        will similarly work for          i = 3, j = 5
//                ^             ^           ^                 ^          a new array will get create, where compare the elements of i and j, 
//                i             j           i                 j          element will get inserted into the new array, and then finally into the
//                                                                       original array...
//                 12 |    |                  8  |    |                  comparing, i and j element, 12 < 35, so 12 will get inserted into the new
//                                                                       array, and i will move ahead


// Index:-        0 | 1         2           3  | 4            5
//               12 | 31       35           8  | 32          17          third, i = 1, j = 2        will similarly work for          i = 4, j = 5
//                    ^         ^                ^            ^          a new array will get create, where compare the elements of i and j, 
//                    i         j                i            j          element will get inserted into the new array, and then finally into the
//                                                                       original array...
//                    12 | 31 | 35                8  | 17 | 32           comparing, i and j element, 31 < 35, so 12 will get inserted into the new
//                                                                       array, and as i cant move further, so element of j will get inserted...


// Index:-        0 | 1  | 2           3  | 4  | 5
//               12 | 31 | 35          8  | 17 | 32                      fourth, i = 0, j = 3   
//                ^                    ^                                 a new array will get create, where compare the elements of i and j, 
//                i                    j                                 element will get inserted into the new array, and then finally into the
//                                                                       original array...
//                  8 |    |    |    |    |                              comparing, i and j element, 12 > 8, so 8 will get inserted into the new
//                                                                       array, and j will move further


// Index:-        0 | 1  | 2           3  | 4  | 5
//               12 | 31 | 35          8  | 17 | 32                      fifth, i = 1, j = 4   
//                    ^                     ^                            a new array will get create, where compare the elements of i and j, 
//                    i                     j                            element will get inserted into the new array, and then finally into the
//                                                                       original array...
//                  8 | 12 |    |    |    |                              comparing, i and j element, 12 < 17, so 12 will get inserted into the new
//                                                                       array, and i will move further


// Index:-        0 | 1  | 2           3  | 4  | 5
//               12 | 31 | 35          8  | 17 | 32                      sixth, i = 1, j = 5   
//                    ^                          ^                       a new array will get create, where compare the elements of i and j, 
//                    i                          j                       element will get inserted into the new array, and then finally into the
//                                                                       original array...
//                  8 | 12 | 17 |    |    |                             comparing, i and j element, 31 > 17, so 17 will get inserted into the new
//                                                                       array, and j will move further


// Index:-        0 | 1  | 2           3  | 4  | 5
//               12 | 31 | 35          8  | 17 | 32                      seventh, i = 2, j = 5   
//                                               ^                       a new array will get create, where compare the elements of i and j, 
//                         i                     j                       element will get inserted into the new array, and then finally into the
//                                                                       original array...
//                  8 | 12 | 17 | 31 |    |                             comparing, i and j element, 31 < 32, so 31 will get inserted into the new
//                                                                       array, and i will move further


// Index:-        0 | 1  | 2           3  | 4  | 5
//               12 | 31 | 35          8  | 17 | 32                      seventh, i = 2, j = 5   
//                                               ^                       a new array will get create, where compare the elements of i and j, 
//                         i                     j                       element will get inserted into the new array, and then finally into the
//                                                                       original array...
//                  8 | 12 | 17 | 31 | 32 | 35                           comparing, i and j element, 35 > 32, so 32 will get inserted into the new
//                                                                       array, and j cant move further, so rest of the elements of another array
//                                                                       will get pushed



// THE REAL ALGORITHM:- 
// 1> Divide the array into two halves until each subarray has one element
// 2> Recursively sort the left half
// 3> Recursively sort the right half
// 4> Initialize pointers i = left subarray start, j = right subarray start
// 5> Compare elements at i and j, copy the smaller element into a temporary array
// 6> Move the pointer (i or j) of the copied element forward
// 7> Repeat steps 5 and 6 until one subarray is exhausted
// 8> Copy remaining elements of the non-exhausted subarray to the temporary array
// 9> Copy the sorted temporary array back to the original array



// O(nlogn) time complexity in best, average, and worst case...
// Space Complexity is O(n) due to use of auxiliary arrays during merging...
// Merge Sort is a stable sort...
// It is not an in-place sorting algorithm...
// It is a recursive algorithm...
// It is not adaptive in nature...