#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0) {
        printf("false\n");
        return false;
    }

    int n2 = x;
    long long int rev = 0;

    while (n2 != 0) {
        rev = 10 * rev + (n2 % 10);
        n2 /= 10;
    }

    if (rev == x) {
        printf("true\n");
        return true;
    } else {
        printf("false\n");
        return false;
    }
}

int main() {
    isPalindrome(1234567899); // Should print "false"
    return 0;
}
