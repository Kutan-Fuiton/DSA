#include<iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string res = "";
        string num = countAndSay(n-1);
        char prev = 0;
        int count = 0; 
        for (char c : num){
            if (prev != c){
                if (count != 0) res += to_string(count) + prev;
                count = 0;
                prev = c;
                count++;
            } else {
                count++;
            }
        }
        if (count >= 1) res += to_string(count) + prev;
        return res;
    }
};

int main(){
    Solution sol;

    cout << sol.countAndSay(30) << endl;

    return 0;
}