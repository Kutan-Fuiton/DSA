#include<stdio.h>
#include<stdlib.h>
#define min(X, Y) (((X) < (Y)) ? (X) : (Y))
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))

int trap(int* height, int heightSize) {
    int * min = (int *)malloc(heightSize * sizeof(int));
    int len=0, count = 0;
    for (int i = 1; i < heightSize-1; i++){
        if ((height[i-1]-height[i]) > 0 && (height[i+1]-height[i]) > 0){min[len++] = i;}
    }
    for (int i = 0; i < len; i++){
        int left = 0, right = 0, k = 1;
        while (k != 0){
            if ((height[min[i] - left] < height[min[i] - left - 1]) && (height[min[i] + right] < height[min[i] + right + 1])){
                count += k * (min(height[min[i] - left - 1], height[min[i] + right + 1]) - max(height[min[i] - left], height[min[i] + right]));
                if (height[min[i]-left-1] > height[min[i]+right+1]){right++;k++;}
                else if (height[min[i]-left-1] < height[min[i]+right+1]){left++;k++;}
                else {left++;right++;k=k+2;}
            } else { k = 0; }
        }
    }
    free(min);
    return count;
}

int main() {
    int s[] = {4,2,0,3,2,5};
    // int s[] = {4,2,0,3,2,5};
    int size = (sizeof(s)/sizeof(s[0]));
    int amt = trap(s,size);

    printf("%d", amt);
    
    return 0;
}