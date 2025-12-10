#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int* majorityElement(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int *res = (int *)malloc(numsSize * sizeof(int));
    int iter = 0;

    if (numsSize == 0){
        *returnSize = 0;
        return res;
    }

    if (numsSize < 3){
        if (numsSize == 1){
            res[0] = nums[0];
            *returnSize = 1;
            return res;
        }
        if (nums[0] == nums[1]){
            res[0] = nums[0];
            *returnSize = 1;
            return res;
        }
        res[0] = nums[0];
        res[1] = nums[1];
        *returnSize = 2;
        return res;
    }

    int n = numsSize / 3;
    int count = 1;

    for (int i = 1; i <= numsSize; i++) {
        if (i < numsSize && nums[i] == nums[i-1]) {
            count++;
        } else {
            if (count > n) {
                res[iter++] = nums[i-1];
            }
            count = 1;
        }
    }

    *returnSize = iter;
    return res;
}

int main() {
    int nums[] = {3, 2, 3};
    int size = (sizeof(nums)/sizeof(nums[0]));
    int returnSize;
    
    int *arr = majorityElement(nums, size, &returnSize);
    int arrsize = (sizeof(nums)/sizeof(nums[0]));
    for (int i = 0; i < returnSize; i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
}