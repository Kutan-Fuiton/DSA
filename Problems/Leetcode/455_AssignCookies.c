#include<stdio.h>
#include<stdlib.h>
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    if (gSize == 0 || sSize == 0){return 0;}
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);
    int j = 0, count = 0;
    for (int i = 0; i < min(sSize, gSize) && j < sSize; i++){
        while (s[j]<g[i]){
            j++;
            if(j == sSize){return count;}
        }
        count++; j++;
    }
    return count;
}

int main() {
    int g[] = {1,2};
    int gsize = sizeof(g)/sizeof(g[0]);
    int s[] = {1, 2, 3};
    int ssize = sizeof(s)/sizeof(s[0]);

    printf("%d", findContentChildren(g, gsize, s, ssize));
    
    return 0;
}