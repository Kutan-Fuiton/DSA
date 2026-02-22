#include<iostream>
using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int i = left; i <= right; i++){
            if (isPrime(__builtin_popcount(i))) count++;
        }
        return count;
    }

private:
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        if (n <= 3) {
            return true;
        }
        if (n % 2 == 0 || n % 3 == 0) {
            return false;
        }
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution sol;
    cout << sol.countPrimeSetBits(10, 15) << endl;
    return 0;
}