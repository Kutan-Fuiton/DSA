#include<stdio.h>

void sortColors(int* nums, int numsSize) {
    int count_0 = 0, count_1 = 0, count_2 = 0;
    for (int i = 0; i < numsSize; i++){
        if (nums[i] == 0){count_0++;}
        else if (nums[i] == 1){count_1++;}
        else {count_2++;}
    }
    for (int i = 0; i < numsSize; i++){
        if (count_0 != 0){
            nums[i] = 0;
            count_0--;
        }
        else if (count_1 != 0){
            nums[i] = 1;
            count_1--;
        }
        else {
            nums[i] = 2;
            count_2--;
        }
    }
}

void printArray(int *A, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {2,0,2,1,1,0};
    int size = sizeof(arr)/sizeof(arr[0]);

    printArray(arr, size);
    sortColors(arr, size);
    printArray(arr, size);
    
    return 0;
}