#include<stdio.h>
#include<string.h>

int romanToInt(char* s) {
    int res = 0;
    for (int i = 0; i < strlen(s); i++){
        if (i > 0 && s[i] == 'M' && s[i-1] == 'C'){res += 800;}       
        else if (s[i] == 'M'){res += 1000;}
        else if (i > 0 && s[i] == 'D' && s[i-1] == 'C'){res += 300;}  
        else if (s[i] == 'D'){res += 500;}
        else if (i > 0 && s[i] == 'C' && s[i-1] == 'X'){res += 80;}   
        else if (s[i] == 'C'){res += 100;}
        else if (i > 0 && s[i] == 'L' && s[i-1] == 'X'){res += 30;}  
        else if (s[i] == 'L'){res += 50;}
        else if (i > 0 && s[i] == 'X' && s[i-1] == 'I'){res += 8;}   
        else if (s[i] == 'X'){res += 10;}
        else if (i > 0 && s[i] == 'V' && s[i-1] == 'I'){res += 3;}    
        else if (s[i] == 'V'){res += 5;}
        else if (s[i] == 'I'){res += 1;}
        else {continue;}
    }
    return res;
}

int main() {
    char s[] = "MCMXCIV";
    printf("%d", romanToInt(s));
    
    return 0;
}