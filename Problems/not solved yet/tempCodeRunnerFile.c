#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char* convert(char* s, int numRows) {
    char * arr = (char*)malloc((strlen(s)+1)*sizeof(char));
    arr[0] = '\0';
    int top = 0, prev= 0, down = 1, count = 0, nxt;
    for (int i = 0; i < strlen(s); i++){
        nxt = (down == 1) ? prev + (2*(numRows-top)-2) : prev + (2*(top));
        if (nxt > strlen(s)-1){top++;count--;}
        if (top >= 0 && top < numRows && count == 0){
            arr[strlen(arr)+1] = '\0';
            arr[i] = s[top];
            
            prev = top;
            if (top == numRows-1){down = 0;}else{down=1;}
            count = 1;
        } else {
            nxt = (down == 1) ? prev + (2*(numRows-top)-2) : prev + (2*(top));

            if (top == 0){down = 1;}
            else if (top == numRows-1){down = 0;} 
            else {down = (down == 1) ? 0 : 1;}
            
            
            prev = nxt;
            arr[strlen(s)+1] = '\0';
            arr[i] = s[nxt];
        }
    }
    return arr;
}