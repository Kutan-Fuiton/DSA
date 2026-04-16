#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int i = 0;
        int n = words.size();

        while (i < n){
            if (words[(startIndex + i)%n] == target) return i;
            if (((startIndex-i)%n < 0) && (words[n+(startIndex - i)%n] == target)) return i;
            if (((startIndex-i)%n >= 0) && (words[(startIndex - i)%n] == target)) return i;

            i++;
        }

        return -1;
    }
};

int main(){
    Solution sol;
    vector<string> words = {"hello","i","am","leetcode","hello"}; string target = "hello"; int start = 1;

    cout << (start + 7)%5 << endl;
    cout << 5+(start - 5)%5 << endl;

    cout << sol.closestTarget(words, target, start) << endl;
    return 0;
}