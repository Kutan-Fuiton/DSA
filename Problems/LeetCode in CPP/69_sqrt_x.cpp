#include<iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long sq = (long long) mid * mid;
            long long next = (long long) (mid + 1) * (mid + 1);

            if (sq <= x && next > x) return mid;

            if (sq > x) high = mid - 1;
            else low = mid + 1;
        }
        return high;
    }
};

int main(){
    Solution sol;

    cout << sol.mySqrt(8) << endl; 
    return 0;
}