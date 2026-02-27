#include<iostream>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;

        while (s != "1"){
            if (s.back() == '0'){
                s.pop_back();
            } else {
                int i = s.size() - 1;

                while (i >= 0 && s[i] == '1'){
                    s[i] = '0';
                    i--;
                }

                if (i >= 0){
                    s[i] = '1';
                } else {
                    s = '1' + s;
                }
            }
            steps++;
        }

        return steps;
    }
};

int main(){
    Solution sol;
    // cout << sol.stepCount(1, 0) << endl;
    // cout << sol.numSteps("1101") << endl;
    cout << sol.numSteps("1111011110000011100000110001011011110010111001010111110001") << endl;
    return 0;
}