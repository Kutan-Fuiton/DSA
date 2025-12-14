#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b){
    return (*(int*)b - *(int*)a);
}

int arrayPairSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int res = 0;
    for (int i = 1; i < numsSize; i=i+2){
        res += nums[i];
    }
    return res;
}

int main() {
    int nums[] = {-100,50,60,70};
    int size = sizeof(nums)/sizeof(nums[0]);

    printf("%d", arrayPairSum(nums, size));
    
    return 0;
}