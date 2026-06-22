#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26); // Track character frequencies
        int max_freq = 0;   // Max frequency of a single character in the current window
        int left = 0;       // Left pointer of the window
        int MAX = 0; // Result stores the longest valid window length
        int n = s.size();

        for (int right = 0; right < n; right++) {
            // Include the current character in the window
            freq[s[right] - 'A']++;
            
            // Update the maximum frequency found in the current window
            max_freq = max(max_freq, freq[s[right] - 'A']);

            // Current window size is (right - left + 1)
            // If the remaining characters to be replaced > k, shrink the window
            if ((right - left + 1) - max_freq > k) {
                freq[s[left] - 'A']--;
                left++; // Move left pointer to shrink the window
            }

            // Update the maximum length of a valid window
            MAX = max(MAX, right - left + 1);
        }

        return MAX;
    }
};

int main(){
    Solution sol;
    cout << sol.characterReplacement("AABABBA", 1) << endl;
    return 0;
}