#include<iostream>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int k = n;
        int bit = 0;
        while (k != 0){
            k = k >> 1;
            bit++;
        }

        return ((1<<bit)-n-1);
    }
};

int main(){
    Solution sol;
    cout << sol.bitwiseComplement(5) << endl;
    return 0;
}