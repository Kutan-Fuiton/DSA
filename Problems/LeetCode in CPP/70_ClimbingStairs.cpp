// we can see a pattern in it...
// n = 1; y = 1 (1)
// n = 2; y = 2 (1+1, 2)
// n = 3; y = 3 (1+1+1, 1+2, 2+1)
// n = 4; y = 5 (1+1+1+1, 2+1+1, 1+2+1, 1+1+2, 2+2)
// n = 5; y = 8 (1+1+1+1+1, 2+1+1+1, 1+2+1+1, 1+1+2+1, 1+1+1+2, 2+2+1, 2+1+2, 1+2+2)

// so the pattern is like this, 1, 2, 3, 5, 8, 13, 21, 34... this is completely a fibonacci series

// now, n = 6, y = 13 and so on...

// by recursion, TLE happening...

#include<iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int prev1 = 1, prev2 = 2;
        int i = 3, res = 0;
        while (i <= n){
            res = prev1 + prev2;
            prev1 = prev2; 
            prev2 = res;
            i++;
        }

        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.climbStairs(8) << endl;
    return 0;
}