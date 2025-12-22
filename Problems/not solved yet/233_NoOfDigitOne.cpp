#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int count = 0;
        for (int i = 1; i <= n; i++){
            count += check(i);
        }
        return count;
    }

private:
    int check(int n){
        int p = n;
        int count = 0;
        while(p != 0){
            if(p%10 == 1) count++;
            p /= 10;
        }
        return count;
    }
};

int main(){
    Solution sol;

    // cout << sol.check(1111021121) << endl;
    cout << sol.countDigitOne(824883294) << endl;

    return 0;
}