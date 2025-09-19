#include <stdio.h>

// 1. Recursive Fibonacci
int fib(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fib(n - 1) + fib(n - 2);
}

// 2. Recursive GCD using Euclidean algorithm
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// 3. Recursive nCr (Combination) using Pascal’s rule
int nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

// 4. Prime checking
int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n, a, b, r;

    // Fibonacci
    printf("Enter n for Fibonacci: ");
    scanf("%d", &n);
    printf("fib(%d) = %d\n", n, fib(n));

    // GCD
    printf("\nEnter two numbers for GCD: ");
    scanf("%d%d", &a, &b);
    printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));

    // nCr
    printf("\nEnter n and r for nCr: ");
    scanf("%d%d", &n, &r);
    printf("%dC%d = %d\n", n, r, nCr(n, r));

    // Prime Check
    printf("\nEnter number to check prime: ");
    scanf("%d", &n);
    printf("%d is %s prime number.\n", n, isPrime(n) ? "a" : "not a");

    return 0;
}