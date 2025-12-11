#include<stdio.h>
#include<stdlib.h>

int trap(int* height, int heightSize) {
    int n = heightSize;
    if (n <= 2) return 0;

    // prev greatest
    int *prev = (int*)malloc(n * sizeof(int));
    prev[0] = -1;
    int max = height[0];

    for (int i = 1; i < n; i++) {
        prev[i] = max;
        if (max < height[i]) max = height[i];
    }

    // next greatest
    int *next = (int*)malloc(n * sizeof(int));
    next[n - 1] = -1;
    max = height[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        next[i] = max;
        if (max < height[i]) max = height[i];
    }

    // mini array
    int *mini = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        mini[i] = (prev[i] < next[i]) ? prev[i] : next[i];
    }

    // calculate water
    int water = 0;
    for (int i = 1; i < n - 1; i++) {
        if (height[i] < mini[i]) {
            water += (mini[i] - height[i]);
        }
    }

    free(prev);
    free(next);
    free(mini);

    return water;
}

int main() {
    int s[] = {3, 5, 3, 2, 3, 2, 4, 1, 6, 4, 1, 3};
    int size = (sizeof(s)/sizeof(s[0]));

    int amt = trap(s,size);
    printf("%d", amt);
    
    return 0;
}