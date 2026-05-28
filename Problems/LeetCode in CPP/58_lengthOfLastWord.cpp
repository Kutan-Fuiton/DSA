#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0; 
        for (int i = s.size()-1; i >= 0; i--){
            if (count == 0 && s[i] == ' ') continue;
            if (s[i] != ' ') count++;
            if (count != 0 && s[i] == ' ') break;
        }
        return count;
    }
};

int main(){
    Solution sol;

    cout << sol.lengthOfLastWord("I am the holy protector  ") << endl;

    return 0;
}