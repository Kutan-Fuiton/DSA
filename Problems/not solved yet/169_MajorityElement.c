#include<stdio.h>
#include<stdlib.h>

int majorityElement(int* nums, int numsSize) {
    int prev = nums[0], count = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == prev) {
            count++;
        } else if (count == 0) {
            prev = nums[i];
            count = 1;
        } else {
            count--;
        }
    }
    return prev;
}

int main() {
    int nums[] = {2,2,1,1,1,2,2};  
    int size = (sizeof(nums)/sizeof(nums[0]));
    
    printf("%d", majorityElement(nums, size));
    
    return 0;
}