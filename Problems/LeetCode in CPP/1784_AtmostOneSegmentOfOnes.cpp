#include <iostream>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        int curr = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1' && (i == 0 || s[i-1] == '0')) {
                curr++;
            }
            if (curr > 1) return false;
        }

        return true;
    }
};

int main(){
    Solution sol;
    cout << sol.checkOnesSegment("10001110010101") << endl;
    return 0;
}