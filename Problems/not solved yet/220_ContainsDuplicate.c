#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int indexDiff, int valueDiff) {
    for (int i = 0; i < numsSize; i++){
        for (int j = i+1; j < numsSize; j++){
            if (abs(i-j) <= indexDiff && abs(nums[i]-nums[j]) <= valueDiff){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int arr[] = {1, 5, 9, 3, 12, 7, 4, 8, 6, 2};
    int size = sizeof(arr)/sizeof(arr[0]);

    if (containsNearbyAlmostDuplicate(arr, size, 3, 2)){
        printf("true");
    } else {printf("false");}
    
    return 0;
}