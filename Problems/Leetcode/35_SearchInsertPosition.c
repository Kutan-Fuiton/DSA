#include<stdio.h>

int binarySearch(int arr[], int element, int low, int high)
{
    if (low > high)
        return low;

    int mid = (low + high) / 2;

    if (high - low == 2) {
        if (arr[mid] == element) return mid;
        if (element > arr[low] && element < arr[mid]) return low + 1;
        if (element > arr[mid] && element < arr[high]) return mid + 1;
    }

    if (high - low == 1) {
        if (arr[low] == element) return low;
        if (arr[high] == element) return high;
        if (element > arr[low] && element < arr[high]) return low + 1;
    }

    if (arr[mid] < element)
        return binarySearch(arr, element, mid + 1, high);

    return binarySearch(arr, element, low, mid - 1);
}

int searchInsert(int* nums, int numsSize, int target) {
    return binarySearch(nums, target, 0, numsSize - 1);
}

int main() {
    int nums[] = {1, 2, 4, 7, 8, 9};
    int size = sizeof(nums)/sizeof(nums[0]);
    printf("%d", searchInsert(nums, size, 5));
    return 0;
}
