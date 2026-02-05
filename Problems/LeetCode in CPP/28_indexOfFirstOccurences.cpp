#include<iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        int i = 0;
        int j = 0;
        int res = -1;
        while (i < haystack.size()) {
            if (haystack[i] == needle[j]) {
                if (j == 0) res = i;   
                i++;
                j++;
                if (j == needle.size()) return res; 
            } else {
                if (j > 0) i = res + 1;
                else i++;
                j = 0;
                res = -1;
            }
        }
        return -1;
    }
};


int main(){
    Solution sol;
    string haystack = "sadbutsad", needle = "sad";

    cout << sol.strStr(haystack, needle) << endl;
    return 0;
}