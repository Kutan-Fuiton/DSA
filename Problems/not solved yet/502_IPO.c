#include<stdio.h>
#include<stdlib.h>

int findMaximizedCapital(int k, int w, int* profits, int profitsSize, int* capital, int capitalSize) {
    if (k > capitalSize){k = capitalSize;}

    int * used = (int *)calloc(capitalSize, sizeof(int));
    int count = 0, i_max;
    while (count < k){
        int max = 0, conf = 0;  

        // deciding the index of project to do to make more profit
        for (int i = 0; i < capitalSize; i++){
            if (used[i]){continue;}
            if (capital[i]<=w && profits[i]>max){
                max = profits[i];
                i_max = i;
                conf = 1;
            }
        }
        if (conf == 0){return w;}
        used[i_max] = 1;

        // doing project and gain profit, increase the capital(w)
        w += profits[i_max];

        // going for next project
        count++;
    }
    free(used);
    return w;
}

int main() {
    int k = 10, w = 0;
    int prof[] = {1,2,3};
    int pSize = sizeof(prof)/sizeof(prof[0]);
    int caps[] = {0,1,2};
    int cSize = sizeof(caps)/sizeof(caps[0]);

    printf("%d", findMaximizedCapital(k, w, prof, pSize, caps, cSize));
    
    return 0;
}