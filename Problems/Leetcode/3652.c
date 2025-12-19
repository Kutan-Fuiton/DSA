#include<stdio.h>

long long maxProfit(int* prices, int pricesSize, int* strategy, int strategySize, int k) {
    long long origin = 0;
    for (int i = 0; i < strategySize; i++) {
        origin += (long long)prices[i] * strategy[i];
    }

    int half = k / 2;
    long long first = 0, second = 0;

    // initial window from 0 to k-1
    for (int i = 0; i < half; i++) {
        first += (long long)prices[i] * strategy[i];
    }
    for (int i = half; i < k; i++) {
        second += (long long)prices[i] * (1 - strategy[i]);
    }

    long long maxProfit = origin - first + second;
    if (origin > maxProfit) maxProfit = origin;

    for (int i = 1; i + k <= pricesSize; i++) {
        // remove outgoing from first half
        first -= (long long)prices[i - 1] * strategy[i - 1];

        // move element from second → first
        first += (long long)prices[i + half - 1] * strategy[i + half - 1];
        second -= (long long)prices[i + half - 1] * (1 - strategy[i + half - 1]);

        // add new element to second half
        second += (long long)prices[i + k - 1] * (1 - strategy[i + k - 1]);

        long long curr = origin - first + second;
        if (curr > maxProfit) maxProfit = curr;
    }

    return maxProfit;
}

int main() {
    int prices[] = {10, 20, 5, 100, 3, 50, 60, 1, 40, 30};
    int pricesSize = sizeof(prices)/sizeof(prices[0]);
    int strategy[] = {1, -1, 0, 1, -1, 0, -1, 1, 0, -1};
    int strategySize = sizeof(strategy)/sizeof(strategy[0]);
    int k = 6;

    printf("%lld", maxProfit(prices, pricesSize, strategy, strategySize, k));
    
    return 0;
}