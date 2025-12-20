#include<stdio.h>
#include<stdlib.h>

int numIdenticalPairs(int* nums, int numsSize) {
    // Maximum element in the array
    int max = 0;
    for (int i = 0; i < numsSize; i++){
        if (nums[i]>max){max = nums[i];}
    }

    // Setting the frequency of those numbers
    int * count = (int *)calloc(max+1, sizeof(int)); 
    for (int i = 0; i < numsSize; i++){
        count[nums[i]]++;
    }

    int res = 0;
    for (int i = 0; i <= max; i++){
        if (count[i] >= 2){
            res += (count[i] * (count[i]-1)/2);
        }
    }

    free(count);
    return res; 
}

int main() {
    int arr[] = {6,5,1,5,7,7,9,1,5,7,1,6,10,9,7,4,1,8,7,1,1,8,6,4,7,4,10,5,3,9,10,1,9,5,5,4,1,7,4,2,9,2,6,6,4,2,10,3,5,3,6,4,7,4,6,4,4,6,3,4,10,1,10,6,10,4,9,6,6,4,8,6,9,5,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("%d", numIdenticalPairs(arr, size));
    
    return 0;
}