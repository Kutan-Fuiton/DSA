#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                int *result = (int *)malloc(2 * sizeof(int));
                if (result == NULL)
                {
                    *returnSize = 0;
                    return NULL;
                }

                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}


int main()
{
    int nums[] = {2, 7, 11, 15};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 13;
    int returnSize;

    int *indices = twoSum(nums, numsSize, target, &returnSize); // Just one line does everything
    printf("[%d, %d]\n", indices[0], indices[1]);

    return 0;
}
