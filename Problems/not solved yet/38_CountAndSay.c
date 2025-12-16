#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* countAndSay(int n) {
    if (n==1){return "1";}
    if (n==2){return "11";}
    char * res = (char *)malloc((n*2)* sizeof(char));    // resultant string
    int len = 0;
    char * hold = (char *)malloc((n*2)* sizeof(char));   // digit holder
    int holdLen = 0;
    char * prev = countAndSay(n-1);             // resultant string of previous count
    int prevLen = strlen(prev);
    int * count = (int *)calloc(prevLen, sizeof(int));   // digit freq holder
    int countLen = 0;
    for (int i = 0; i < prevLen; i++) {
        if (i < prevLen - 1 && prev[i] != prev[i+1]){
            count[countLen]++;
            countLen++;
            hold[holdLen++] = prev[i];
        } else if (i == prevLen - 1){
            if (prev[i] != prev[i-1]){
                count[countLen]++;
                countLen++;
                hold[holdLen++] = prev[i];
            } else {
                count[countLen]++;
            }
        } else {
            count[countLen]++;
        }
    }
    for (int i = 0; i < 2 * countLen; i++){
        if (i % 2 == 0){res[len++] = count[i/2]+'0';}
        else {res[len++] = hold[i/2];}
    }
    return res;
}

int main() {
    printf("%s", countAndSay(3));
    
    return 0;
}