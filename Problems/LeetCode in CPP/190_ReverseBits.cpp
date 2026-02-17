#include<iostream>
#include<algorithm>
#include<bitset>
#include<string>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        string bin = bitset<32>(n).to_string();   // converts number to binary string
        reverse(bin.begin(), bin.end());          // reverse the binary string
        return stoi(bin, nullptr, 2);             // converts binary string to number
    }
};

int main(){
    Solution sol;
    cout << sol.reverseBits(2147483644) << endl;

    return 0;
}