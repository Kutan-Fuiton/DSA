#include<iostream>

using namespace std;

class Solution {
public:
    int mirrorDistance(int n) {
        int rev = 0;
        int temp = n;
        while (temp > 0){
            rev = rev * 10 + (temp%10);
            temp /= 10;
        }
        return abs(rev - n);
    }
};

int main(){
    Solution sol;
    cout << sol.mirrorDistance(67) << endl;
    return 0;
}