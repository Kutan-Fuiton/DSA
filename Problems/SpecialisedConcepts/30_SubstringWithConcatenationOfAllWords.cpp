#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;

        int wordLen = words[0].size();  // Every word in words is of same size.
        int wordsLen = words.size();   
        int permtLen = wordLen * wordsLen;  
        int sLen = s.length();

        if (sLen < permtLen) return res; // If s is too short

        // Creating the frequency map of words
        unordered_map<string, int> freq;
        for (const string& word : words) {
            freq[word]++;
        }

        // We only need to run the sliding window 'wordLen' times
        for (int i = 0; i < wordLen; ++i) {
            int left = i;
            int right = i;
            unordered_map<string, int> temp;
            int count = 0; // Tracks how many valid words are currently in our window

            // Move the right pointer across the string by 'wordLen' steps
            while (right + wordLen <= sLen) {
                // Slicing out the next word chunk at the right pointer
                string chunk = s.substr(right, wordLen);
                right += wordLen;

                // The chunk is a valid word from our master list
                if (freq.find(chunk) != freq.end()) {
                    temp[chunk]++;
                    count++;

                    // If we have too many duplicates of this word, shrink the window from the left
                    while (temp[chunk] > freq[chunk]) {
                        string leftChunk = s.substr(left, wordLen);
                        temp[leftChunk]--;
                        count--;
                        left += wordLen;
                    }

                    // If our window contains exactly the number of words we need
                    if (count == wordsLen) {
                        res.push_back(left);
                    }
                } 
                // The chunk is completely invalid, reset the window
                else {
                    temp.clear();
                    count = 0;
                    left = right; 
                }
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<string> words = {"foo", "bar"};
    string s = "barfoothefoobarman";

    vector<int> out = sol.findSubstring(s, words);
    for (int i = 0; i < out.size(); i++){
        cout << out[i] << " ";
    }cout << endl;
    return 0;
}