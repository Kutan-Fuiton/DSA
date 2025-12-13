#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int length(const char * s) {
    int len = 0;
    while (s[len] != '\0') len++;
    return len;
}

bool isMatch(char* s, char* p) {
    int sSize = length(s);
    int pSize = length(p);
    int * pass = (int *)calloc(sSize, sizeof(int));
    int i = 0, j = 0, pass = 0;
    int dot=0, star=0;
    while (i < pSize){
        if (p[i+1] == "*"){star = 1;}
        if (star == 1){
            while (s[j] != p[i+2]){
                pass[j++] = 1;
            }
            star = 0;
        }
        else if (p[i] == "." && p[i] == s[j]){
            pass[j++] = 1;
            i++;
        } else {
            j++;i++;
        }
    }
}

int main() {
    char * s = "aabbbbc";
    char * p = "a.*b*c";

    printf("%d\n", length(s));
    printf("%d\n", length(p));

    // if (isMatch(s, p)){printf("true");}
    // else {printf("false");}
    
    return 0;
}