#include<stdio.h>
#include<stdlib.h>

int length(char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

char* addBinary(char* a, char* b) {
    int max = length(a) > length(b) ? length(a) : length(b);
    char* result = (char*)malloc((max + 2)*sizeof(char)); 
    int carry = 0;
    for (int i = 0; i < max; i++) {
        int bitA = (i < length(a)) ? a[length(a) - 1 - i] - '0' : 0;
        int bitB = (i < length(b)) ? b[length(b) - 1 - i] - '0' : 0;
        
        int sum = bitA + bitB + carry;
        result[max - i] = (sum % 2) + '0'; 
        carry = sum / 2; 
    }
    result[0] = carry ? '1' : '0'; 
    result[max + 1] = '\0';
    if (result[0] == '0') {
        for (int i = 1; i <= max; i++) {
            result[i - 1] = result[i];
        }
        result[max] = '\0';
    }
    return result;
}

int main() {
    char * s1 = "11";
    char * s2 = "1";

    char * result = addBinary(s1, s2);
    printf("Result: %s\n", result);
    
    return 0;
}