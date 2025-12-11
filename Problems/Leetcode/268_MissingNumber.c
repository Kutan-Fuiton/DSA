#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int missingNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize; i++){
        if (nums[i] != i){
            return i;
        }
    }
    return numsSize;
}

int main() {
    int arr[] = {0,1};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("%d", missingNumber(arr, size));
    
    return 0;
}