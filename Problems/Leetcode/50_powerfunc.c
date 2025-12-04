#include<stdio.h>
#include<stdlib.h>

double myPow(double x, int n) {
    if (x == 0.0) {
        if (n == 0) return 1.0;
        if (n < 0) return 1.0 / x; // Invalid: Division by zero
        return 0.0;
    }
    double result = 1.0;
    long long N = n; 
    if (N < 0) {
        N = -N;
        x = 1.0 / x; 
    }
    while (N > 0) {
        if (N % 2 == 1) {
            result *= x;
        }
        x *= x;
        N /= 2;
    }
    return result;
}

int main() {
    printf("Power: %lf\n", myPow(2.00000, -2147483648));
    
    return 0;
}