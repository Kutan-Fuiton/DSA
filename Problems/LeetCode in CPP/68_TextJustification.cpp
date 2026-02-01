#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // length of each words stored
        vector<int> len;
        for (const string& s : words) {
            len.push_back(s.size());
        }

        // wordsperline[i] = {number_of_words, sum_of_word_lengths}
        vector<vector<int>> wordsperline;
        int count = 0;
        int start = 0;
        for (int i = 0; i < words.size(); i++) {
            if (count + len[i] + (i - start) > maxWidth) {
                wordsperline.push_back({i - start, count});
                start = i;
                count = 0;
            }
            count += len[i];
        }
        wordsperline.push_back({(int)words.size() - start, count});

        // gaps distribution
        vector<vector<int>> gaps;
        for (int i = 0; i < wordsperline.size(); i++) {
            int k = wordsperline[i][0]; // no. of words
            int l = wordsperline[i][1]; // total length of letters per line
            int extras = maxWidth - l;
            vector<int> linegaps;
            if (i == wordsperline.size() - 1 || k == 1) {
                for (int j = 0; j < k - 1; j++) {
                    linegaps.push_back(1);
                    extras--;
                }
                if (extras > 0) linegaps.push_back(extras);
            } else {
                int gap = k - 1;
                int even = extras / gap;
                int left = extras % gap;
                for (int j = 0; j < gap; j++) {
                    linegaps.push_back(even + (j < left ? 1 : 0));
                }
            }
            gaps.push_back(linegaps);
        }

        // forming the string
        vector<string> res;
        int st = 0;
        for (int i = 0; i < wordsperline.size(); i++) {
            int x = wordsperline[i][0];
            string temp = "";
            for (int j = 0; j < x; j++) {
                temp += words[st + j];
                if (j < gaps[i].size()) {
                    temp.append(gaps[i][j], ' ');
                }
            }
            res.push_back(temp);
            st += x;
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;

    vector<string> res = sol.fullJustify(words, maxWidth);

    for (const string s : res){
        cout << s << endl;
    }

    return 0;
}