#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Helper Function
char* string(int num) {
    int length = snprintf(NULL, 0, "%d", num);
    char* str = malloc(length + 1);
    if (str == NULL) return NULL;
    snprintf(str, length + 1, "%d", num);
    return str;
}

char* getHint(char* secret, char* guess) {
    int len = strlen(secret);
    int * count = (int *)calloc(10, sizeof(int));
    int * count2 = (int *)calloc(10, sizeof(int));
    int bull = 0;
    for (int i = 0; i < len; i++){
        if (secret[i] == guess[i]){bull++;}
        count[(secret[i] - '0')]++;
        count2[(guess[i] - '0')]++;
    }

    int total = 0;
    for (int i = 0; i < 10; i++){
        if (count[i] >= 1 && count2[i] >= 1){
            total += (count[i]<count2[i]) ? count[i] : count2[i];
        }
    }
    int cow = total - bull;

    char * bullstr = string(bull);
    char * cowstr = string(cow);
    char * res = (char *) calloc (strlen(bullstr)+strlen(cowstr)+3, sizeof(char));
    strcat(res, bullstr);
    strcat(res, "A");
    strcat(res, cowstr);
    strcat(res, "B");

    free(count);
    free(count2);
    free(bullstr);
    free(cowstr);

    return res;
}

int main() {
    char * secret = "1123";
    char * guess = "0111";

    printf("%s", getHint(secret, guess));
    
    return 0;
}