#include <stdio.h>

int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("\nEnter number to check prime: ");
    scanf("%d", &n);
    printf("%d is %s prime number.\n", n, isPrime(n) ? "a" : "not a");

    return 0;
}