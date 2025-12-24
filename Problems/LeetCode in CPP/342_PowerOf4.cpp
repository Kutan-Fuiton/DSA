#include<iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n < 1){return false;}
        int p = n;
        while (p != 0){
            if (p % 4 != 0 && p != 1){
                return false;
            }
            p /= 4;
        }
        return true; 
    }
};

int main(){
    Solution sol;
    int n = 32;

    if (sol.isPowerOfFour(n)){
        cout << "True";
    } else {
        cout << "False";
    }

    return 0;
}