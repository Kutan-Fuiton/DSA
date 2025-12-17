#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void* b) {
    const int* pair1 = *(const int**)a;  
    const int* pair2 = *(const int**)b;  
    
    if (pair1[0] != pair2[0]) {
        return pair1[0] - pair2[0];
    }
    return pair1[1] - pair2[1];
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize) {
    *envelopesColSize = 2;
    int count = 0, iter = 0;
    qsort(envelopes, envelopesSize, sizeof(envelopes[0]), cmp);
    for (int i = 0; i < envelopesSize - 1; i++){
        if ((envelopes[iter][0] < envelopes[i+1][0]) && (envelopes[iter][1] < envelopes[i+1][1])){
            count++;
            iter++;
        }
        if ((envelopes[iter][0] == envelopes[i+1][0]) && (envelopes[iter][1] == envelopes[i+1][1])){
            iter++;
        }
    }
    return count + 1;
}

int main() {
    int arr[][2] = {{4,5},{4,6},{6,7},{2,3},{1,1},{1,1}};
    int row = sizeof(arr) / sizeof(arr[0]); 
    int col;

    int* pointers[row];
    for (int i = 0; i < row; i++) {
        pointers[i] = arr[i];  
    }

    printf("%d\n", maxEnvelopes(pointers, row, &col));
    
    qsort(pointers, row, sizeof(pointers[0]), cmp);
    
    for (int i = 0; i<row; i++){
        printf("%d, %d\n", pointers[i][0], pointers[i][1]);
    }
    
    return 0;
}