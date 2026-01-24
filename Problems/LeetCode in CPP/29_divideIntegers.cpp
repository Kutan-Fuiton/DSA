#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT32_MIN && divisor == -1)
            return INT32_MAX;

        bool negative = (dividend < 0) ^ (divisor < 0);

        long long a = llabs(dividend);
        long long b = llabs(divisor);

        long long quotient = 0;

        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            while ((temp << 1) <= a) {   // checking 2 * divisor <= dividend
                temp <<= 1;           // temp = temp << 1 ---> temp = temp * 2^1   ---> temp = 2 * temp`
                multiple <<= 1;       // multiple  = 2 * multiple;
            }

            a -= temp;               // dividend = dividend - divisor;
            quotient += multiple;    // quotient = quotient + multiple;  
        }

        return negative ? -quotient : quotient;
    }
};


int main(){
    Solution sol;

    // cout << sol.divide(10, 3) << endl;
    // cout << sol.divide(7, -3) << endl;

    return 0;
}