#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* decodeString(char* s) {
    char *temp = (char *)malloc(1000 * sizeof(char));   // everything inside bracket
    temp[0] = '\0';
    char *result = (char *)malloc(1000 * sizeof(char));   // final result string
    result[0] = '\0';
    char *numStr = (char *)malloc(10 * sizeof(char));   // to store number as string
    numStr[0] = '\0';
    char *p = s;
    int num = 0, count = 0;
    while (*p != '\0') {
        if (count == 0 && (*p >= 'a' && *p <= 'z')) {
            int len = strlen(result);
            result[len] = *p;
            result[len + 1] = '\0';
            p++;
        }
        else if (count == 0 && (atoi(p) >= 0 && atoi(p) <= 9)){
            int len = strlen(numStr);
            numStr[len] = *p;
            numStr[len + 1] = '\0';
            if (*(p + 1) >= '0' && *(p + 1) <= '9') {
                p++;
                continue;
            } else {
                num = atoi(numStr);
                numStr[0] = '\0';
                p++;
            }
        }
        else if (*p == '[') {
            count++;
            if (count > 1) {
                int len = strlen(temp);
                temp[len] = *p;
                temp[len + 1] = '\0';
            }
            p++;
        }
        else if (count > 0) {
            if (*p == ']'){
                count--;
                if (count == 0) {
                    for (int i = 0; i < num; i++) {
                        result = strcat(result, decodeString(temp));
                    }
                    temp[0] = '\0';
                }
                p++;
            }
            int len = strlen(temp);
            temp[len] = *p;
            temp[len + 1] = '\0';
            p++;
        }
        else {
            printf("Bhadwe!");
        }
    }
    return result;
}

int main() {
    char s[100] = "c3[a2[c]]";

    char * decodedString = decodeString(s);
    printf("Decoded String of %s: %s\n", s, decodedString);
    
    return 0;
}