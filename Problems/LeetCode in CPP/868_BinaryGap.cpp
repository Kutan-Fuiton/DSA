#include<iostream>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        if (n == 0){
            return 0;
        }

        int count = 0, res = 0;

        while (n > 0){
            if (n%2 == 1){
                res = max(res, count);
                count = 1;
            } else if (count>=1) {
                count++;
            }

            n /= 2;
        }

        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.binaryGap(8) << endl;
    return 0;
}