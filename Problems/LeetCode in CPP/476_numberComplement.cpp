#include<iostream>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int n = 0, temp = num;
        long long high = 1;

        while (temp != 0){
            temp/=2;
            high*=2;
            n++;
        }

        return (high - 1 - num);
    }
};

int main(){
    Solution sol;
    cout << sol.findComplement(5) << endl;
    cout << sol.findComplement(7) << endl;
    cout << sol.findComplement(13) << endl;
    cout << sol.findComplement(1) << endl;
    cout << sol.findComplement(46) << endl;
    return 0;
}