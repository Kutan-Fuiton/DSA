//  0 1  2  3 4
// [3 30 34 5 9]

// 9534330

//  4 3 2  0 1
// [9 5 34 3 30]


#include<stdio.h>
#include<stdlib.h>

int len(int x) {
    int num = x, count = 0;
    if (x==0){
        return 1;
    }
    while (num > 0) {
        num /= 10;
        count++;
    }
    return count;
}

int firstDigit(int x) {
    int num = x;
    while (num >= 10) {
        num /= 10;
    }
    return num;
}

char* largestNumber(int* nums, int numsSize) {
    int length = 0;
    for (int i = 0; i < numsSize; i++){
        length += len(nums[i]);
    }
    char *str = (char*) malloc (length+1);
    // char *str = "9534330";
    return str;

}

int main() {
    int arr[] = {3,30,34,5,9};
    int numsSize = 5;
    char* str = largestNumber(arr, numsSize);
    printf("%s\n", str);
    
    return 0;
}