#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }
    return false;
}

int main() {
    int arr[] = {1,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);

    bool result = containsDuplicate(arr, size);
    printf("Contains Duplicate: %s\n", result ? "true" : "false");
    
    return 0;
}