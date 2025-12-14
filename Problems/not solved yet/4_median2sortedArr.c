#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size){
    int total = nums1Size + nums2Size;
    int *arr = (int *)malloc(((total / 2) + 1) * sizeof(int));
    int j = 0, k = 0;
    for (int i = 0; i <= total / 2; i++){
        if (j < nums1Size && k < nums2Size){
            if (nums1[j] < nums2[k]){
                arr[i] = nums1[j];
                j++;
            } else {
                arr[i] = nums2[k];
                k++;
            }
        } else if (j < nums1Size){
            arr[i] = nums1[j];
            j++;
        } else {
            arr[i] = nums2[k];
            k++;
        }
    }
    double result;
    if (total % 2 == 0){
        result = (double)(arr[(total/2)-1] + arr[total/2]) / 2;
    } else {
        result = (double)arr[total/2];
    }

    free(arr);
    return result;
}

int main()
{
    int nums1[] = {1, 2};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int nums2[] = {3, 4};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);

    printf("%f", findMedianSortedArrays(nums1, size1, nums2, size2));

    return 0;
}