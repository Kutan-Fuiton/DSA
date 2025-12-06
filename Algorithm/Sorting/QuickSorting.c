#include<stdio.h>

void printArray(int *A, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low+1;
    int j = high;
    int temp;

    do {
        while(A[i]<=pivot){
            i++;
        }
        while(A[j]>pivot){
            j--;
        }
        if (i<j){
            // Swap A[i] & A[j]
            temp = A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    } while(i<j);

    // Swap A[low] & A[j] 
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high){
    if (low<high){
        int partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex-1);
        quickSort(A, partitionIndex+1, high);
    }
}


int main() {
    int A[]={3, 5, 2, 13, 12, 3, 3, 13, 45};
    int n = (sizeof(A)/sizeof(A[0]));
    
    printf("Original arr: ");
    printArray(A, n);

    quickSort(A, 0, n-1);
    
    printf("Sorted array: ");
    printArray(A, n);
    
    return 0;
}







// Quick Sort Implementation in C

// Less assume an array of integers and its size are given, let the size is 10...

// Index:-        0 | 1 | 2 | 3 | 4 | 5  | 6 | 7 | 8 | 9 
// Values:-       2 | 4 | 3 | 9 | 1 | 4' | 8 | 7 | 5 | 6

// Sorted arr:-   1 | 2 | 3 | 4 | 4 | 5  | 6 | 7 | 8 | 9

// In this algorithm, we declare the first element (0th element) as pivot, and do a partition, where on the left side of the partition there will be all the numbers less than pivot element and on the right side of the partition there will be all the numbers greater than pivot element...
// and then right after the pivot element, 'i' will iterate to the right, and 'j' will iterate from last to left...
// i will check for greater element while j will check for lesser or equal element... it would be done until j <= i...
// [Coding Term]: will take pivot as low and last element as high always...

// Algorithm:-
// Index:-        0 | 1 | 2 | 3 | 4 | 5  | 6 | 7 | 8 | 9 

//                2 | 4 | 3 | 9 | 1 | 4' | 8 | 7 | 5 | 6       => making the first element pivot, 'i' will start from 4, 4 > 2, so i will stop on 
//                ^   ^                                ^          1th index, jth pos = 6, which is > 2, but j want lesser(or equal) than 2, j will 
//                ^   i                                j          go to next index (i.e., j--)

//                2 | 4 | 3 | 9 | 1 | 4' | 8 | 7 | 5 | 6       => j is 5 now, 2 < 5, so j will move ahead...
//                ^   ^                            ^               
//                ^   i                            j              

//                2 | 4 | 3 | 9 | 1 | 4' | 8 | 7 | 5 | 6       => j is 7 now, 2 < 7, so j will move ahead...
//                ^   ^                        ^                   
//                ^   i                        j                  

//                2 | 4 | 3 | 9 | 1 | 4' | 8 | 7 | 5 | 6       => j is 8 now, 2 < 8, so j will move ahead... 
//                ^   ^                    ^                      
//                ^   i                    j                      

//                2 | 4 | 3 | 9 | 1 | 4' | 8 | 7 | 5 | 6       => j is 4 now, 2 < 4, so j will move ahead...
//                ^   ^               ^                         
//                ^   i               j                           

//                2 | 4 | 3 | 9 | 1 | 4' | 8 | 7 | 5 | 6       => j is 1 now, 2 > 1, so j will stop now...  
//                ^   ^           ^                               now ith element and jth element will swap... 4 <-> 1 ...
//                ^   i           j                               

//                2 | 1 | 3 | 9 | 4 | 4' | 8 | 7 | 5 | 6       => i is 1 now, 2 > 1, so i will move ahead... 
//                ^   ^           ^                               
//                ^   i           j                               

//                2 | 1 | 3 | 9 | 4 | 4' | 8 | 7 | 5 | 6       => i is 3 now, 2 < 3, so i will stop now...
//                ^       ^       ^                               but j is 4, 2 < 4, so j will move ahead...
//                ^       i       j                               

//                2 | 1 | 3 | 9 | 4 | 4' | 8 | 7 | 5 | 6       => j is 9 now, 2 < 9, so j will move ahead...
//                ^       ^   ^                               
//                ^       i   j                               

//                2 | 1 | 3 | 9 | 4 | 4' | 8 | 7 | 5 | 6       => j is 3 now, 2 < 3, so j will move ahead...
//                ^       ^^                               
//                ^       ij                               

//                2 | 1 | 3 | 9 | 4 | 4' | 8 | 7 | 5 | 6       => j is 1 now, 2 < 1, so j will stop now...
//                ^   ^   ^                                       and also at this point, j crossed i ...
//                ^   j   i                                       so now have to interchange the pivot element and jth element... 2 <-> 1...

//                1 | 2 | 3 | 9 | 4 | 4' | 8 | 7 | 5 | 6       => now the current pivot element is at index 1, which creates a partition between
//                    ^                                           two arrays now...
//                    ^                                           {1} & {3, 9, 4, 4', 8, 7, 5, 6}, now will use same technique on these two arrays
//                                                                for 2nd array, 3 will be pivot, i will start from 9 and j will start from 6...
// It's a recursive process...                                    and it goes on... like the same way... i am showing it in short...

//                1 | 2 | 3 | 9 | 4 | 4' | 8 | 7 | 5 | 6       => 
//                  |   | ^   ^                        ^           
//                  |   | ^   i                        j          

//                1 | 2 | 3 | 9 | 4 | 4' | 8 | 7 | 5 | 6       => Here the partition element stays 3 only 
//                  |   | ^^  ^                                   
//                  |   | ^j  i                                  

//                1 | 2 | 3 | 9 | 4 | 4' | 8 | 7 | 5 | 6       => 
//                      |   | ^   ^                    ^              
//                      |   | ^   i                    j             

//                1 | 2 | 3 | 9 | 4 | 4' | 8 | 7 | 5 | 6       => here j < = i, swap pivot and j th element, partition element stays 9 only
//                      |   | ^                       ^^              
//                      |   | ^                       ij             

//                1 | 2 | 3 | 6 | 4 | 4' | 8 | 7 | 5 | 9       => 
//                      |   | ^   ^                ^ |                
//                      |   | ^   i                j |                

//                1 | 2 | 3 | 6 | 4 | 4' | 8 | 7 | 5 | 9       => at i, 8>6, at j, 5<6, so now swap i and j 
//                      |   | ^            ^       ^ |                
//                      |   | ^            i       j |                

//                1 | 2 | 3 | 6 | 4 | 4' | 5 | 7 | 8 | 9       => j < i, so swap pivot and j... 
//                      |   | ^            ^   ^     |                
//                      |   | ^            j   i     |                

//                1 | 2 | 3 | 5 | 4 | 4' | 6 | 7 | 8 | 9       => 
//                      |   | ^   ^   ^  |   | ^   ^ |                
//                      |   | ^   i   j  |   | ^   i |                

//                1 | 2 | 3 | 5 | 4 | 4' | 6 | 7 | 8 | 9       => in 1st arr, pivot and j will swap
//                      |   | ^      ^^  |   | ^   ^ |            in 2nd arr, as i > pivot, so will keep it like that untouched..    
//                      |   | ^      ij  |   | ^   i |                


//                1 | 2 | 3 | 4'| 4 | 5  | 6 | 7 | 8 | 9       => will be untouched as i = pivot...
//                      |   | ^   ^ |                              
//                      |   | ^   i |                                 

//                1 | 2 | 3 | 4'| 4 | 5  | 6 | 7 | 8 | 9       => After all these passes, the array is sorted...

// THE REAL ALGORITHM:- 
// 1> i = low
// 2> j = high
// 3> pivot = low
// 4> i++ until element > pivot is found
// 5> j-- until element < pivot is found
// 6> swap A[i] & A[j] and repeat step 4 and 5 until i > j
// 7> swap pivot & A[j]



// O(nlogn) time complexity... best case is O(n) when the array is already sorted... worst case is O(n^2)... best case is O(nlogn)...
// Space Complexity is O(1) as we are not using any extra space except some variables...
// Quick Sort is a not stable sort... For example, check the example given above...
// It is an in-place sorting algorithm...
// It is a recursive algorithm...
// It is by defualt not adaptive in nature...