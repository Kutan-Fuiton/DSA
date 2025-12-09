#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* convert(char* s, int numRows) {\
    int len = strlen(s);
    if (numRows >= len || numRows == 1){return s;} 
    char *arr = (char*)malloc((len + 1) * sizeof(char));
    int pos = 0;
    int top = 0, prev = 0, down = 1, count = 0, nxt;

    for (int i = 0; i < len; i++) {
        nxt = (down == 1) ? prev + (2 * (numRows - top) - 2) : prev + (2 * top);
        if (nxt >= len && i != 0) { top++; count--; }
        printf("%d:- %d, %d, %d, %d, %d\n", i, top, prev, down, count, nxt);

        if (top >= 0 && top < numRows && count == 0) {
            arr[pos++] = s[top];
            prev = top;
            down = (top == numRows - 1) ? 0 : 1;
            count = 1;
            printf("%d:- %d, %d, %d, %d, %d\n", i, top, prev, down, count, nxt);
        } else {
            nxt = (down == 1) ? prev + (2 * (numRows - top) - 2) : prev + (2 * top);
            if (top == 0) down = 1;
            else if (top == numRows - 1) down = 0;
            else down = !down;

            prev = nxt;
            if (nxt >= 0 && nxt < len) arr[pos++] = s[nxt];
            printf("%d:- %d, %d, %d, %d, %d\n", i, top, prev, down, count, nxt);
        }
    }

    arr[pos] = '\0';
    return arr;
}

int main() {
    char s[] = "ABCD";

    printf("index, top, prev, down, count, next\n");
    printf("%s",convert(s, 3));

    return 0;
}