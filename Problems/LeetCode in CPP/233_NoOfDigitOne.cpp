#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        long long fact = 1;
        long long count = 0;

        while (fact <= n) {
            long long low  = n % fact;
            long long curr = (n / fact) % 10;
            long long high = n / (fact * 10);

            if (curr == 0)
                count += high * fact;
            else if (curr == 1)
                count += high * fact + low + 1;
            else
                count += (high + 1) * fact;

            fact *= 10;
        }

        return (int)count;
    }
};

int main(){
    Solution sol;

    cout << sol.countDigitOne(1000000000) << endl;

    return 0;
}