#include<stdio.h>
#include<stdlib.h>

void print(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Merge Sorting Algorithm
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1; 
    int n2 = right - mid;    

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; 
    j = 0; 
    k = left; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int maximumGap(int* nums, int numsSize) {
    if (numsSize == 0 || numsSize == 1){
        return 0;
    }
    mergeSort(nums, 0, numsSize-1);
    int max = 0;
    for (int i = 0; i < numsSize - 1; i++){
        int absol = abs(nums[i+1]-nums[i]);
        if (absol > max){
            max = absol;
        }
    }
    return max;
}

int main() {
    int arr[] = {7, 11, -3 ,9};   
    int size = (sizeof(arr)/sizeof(arr[0]));

    mergeSort(arr, 0, size-1);
    print(arr, size);

    printf("Maximum Gap: %d\n", maximumGap(arr, size));
    
    return 0;
}