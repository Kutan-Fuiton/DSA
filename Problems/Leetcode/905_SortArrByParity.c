#include<stdio.h>
#include<stdlib.h>

int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int * res = (int *)malloc(numsSize * sizeof(int));
    int i = 0, j = numsSize-1, k = 0;
    while (k < numsSize){
        if (nums[k]%2 == 0){
            res[i] = nums[k];
            i++;
        } else {
            res[j] = nums[k];
            j--;
        }
        k++;
    }
    return res;
}

int main() {
    int arr[] = {11, 12, 13, 14, 15, 16, 17, 18};
    int size = sizeof(arr)/sizeof(arr[0]);
    int resSize;

    int * nums = sortArrayByParity(arr, size, &resSize);
    for (int i = 0; i < size; i++){
        printf("%d ", nums[i]);
    }


    return 0;
}