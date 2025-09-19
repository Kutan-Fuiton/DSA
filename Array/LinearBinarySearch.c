// Linear Search means searching an element one by one in a given array. The more the size of the array the more time it will take to search an element. The time complexity of linear search is O(n) where n is the size of the array. This works for both sorted and unsorted arrays.

#include <stdio.h>

// Code for Linear Search
int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

// int binarySearch(int arr[], int size, int element)
// {
//     int low = 0, mid, high = size - 1;

//     // Keep Searching until low <= high
//     while (low <= high)
//     {
//         mid = (low + high) / 2; // It automatically takes the floor value if the mid is in decimal
//         if (arr[mid] == element)
//         {
//             return mid;
//         }
//         if (arr[mid] < element)
//         {
//             low = mid + 1;
//         }
//         else
//         {
//             high = mid - 1;
//         }
//     }
//     return -1;
// }

int binarySearch(int arr[], int size, int element, int low, int high)
{
    // int low = 0, mid, high = size - 1;

    int mid = (low + high) / 2; // It automatically takes the floor value if the mid is in decimal
    if (arr[mid] == element)
    {
        return mid;
    }
    if (arr[mid] < element)
    {
        low = mid + 1;
        binarySearch(arr, size, element, low, high);
    }
    else
    {
        high = mid - 1;
        binarySearch(arr, size, element, low, high);
    }
    return -1;
}

int main()
{
    // Unsorted array for linear search
    // int arr[] = {2, 4, 0, 1, 9, 10, 15, 8};
    // int size = sizeof(arr)/sizeof(int);
    // int element = 9;
    // int searchIndex = linearSearch(arr, size, element);
    // printf("The element %d was found at index %d \n", element, searchIndex);

    // Sorted array for binary search
    int arr[] = {1, 3, 5, 56, 64, 73, 123, 225, 444};
    int size = sizeof(arr) / sizeof(int);
    int element = 444;
    // int searchIndex = binarySearch(arr, size, element);
    int searchIndex = binarySearch(arr, size, element, 0, size - 1);
    printf("The element %d was found at index %d \n", element, searchIndex);

    return 0;
}