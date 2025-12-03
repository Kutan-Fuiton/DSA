#include<stdio.h>
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* res = (int*)malloc(numsSize * sizeof(int));
    if (numsSize == 0 || numsSize == 1) {
        res[0] = -1;
        return res;
    }
    for (int i = 0; i < numsSize; i++) {  
        int j = i + 1;
        while (j % numsSize != i) {
            if (nums[j % numsSize] > nums[i]) {
                res[i] = nums[j % numsSize];
                break;
            } else {
                res[i] = -1;
            }
            j++;
        }
    }
    return res;
}

int main() {
    int nums[] = {5,4,3,2,1};
    int numSize = 5;
    int returnSize;

    int * arr = nextGreaterElements(nums, numSize, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}