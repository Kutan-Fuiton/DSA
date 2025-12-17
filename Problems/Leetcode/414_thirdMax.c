#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x < y) return 1;
    if (x > y) return -1;
    return 0;
}

int thirdMax(int* nums, int numsSize) {
    if (numsSize == 0){return 0;}
    qsort(nums, numsSize, sizeof(int), cmp);
    if (numsSize < 3){return nums[0];}
    int count = 0;
    for (int i = 0; i < numsSize && count < 3; i++){
        if (i != 0 && nums[i] == nums[i-1]){continue;}
        count++;
        if (count == 3){return nums[i];}
    }
    return nums[0];
}

int main() {
    int nums[] = {-2147483648, 0, 2147483647};    // 5554321
    int size = sizeof(nums)/sizeof(nums[0]);

    printf("%d", thirdMax(nums, size));
    
    return 0;
}