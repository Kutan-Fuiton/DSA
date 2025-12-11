
// int trap(int* height, int heightSize) {
//     int * max = (int *)malloc(heightSize * sizeof(int));
//     int len=0;
//     for (int i = 0; i < heightSize; i++){
//         if (i == 0 && (height[i]>height[i+1])){max[len++] = i;printf("%d: %d\n", i, height[i]);}
//         else if (i == heightSize - 1 && (height[i]>height[i-1])){max[len++] = i;printf("%d: %d\n", i, height[i]);}
//         else if ((height[i]>height[i-1]) && (height[i]>height[i+1])){max[len++] = i;printf("%d: %d\n", i, height[i]);}
//         else {continue;}
//     }
//     return len;
// }