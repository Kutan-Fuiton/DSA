#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
#include<utility>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // inputing everything in the dictionary in a hashset for O(1) search
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // if endword is not in the dictionary then return 0
        if (!wordSet.count(endWord)) return 0;

        // remove beginWord so we don't visit it again
        wordSet.erase(beginWord);
        
        // initialising queue with (beginWord, 1)
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()){
            pair<string, int> temp = q.front();
            q.pop();

            string word = temp.first;
            int level   = temp.second;

            // check whether we get the endword or not
            if (word == endWord) return level;

            for (int i = 0; i < word.size(); ++i){
                char ori = word[i]; // saving the original character

                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    if (ori == ch) continue;

                    word[i] = ch;

                    if (wordSet.count(word)){
                        q.push({word, level+1});
                        wordSet.erase(word);
                    }
                }

                word[i] = ori;
            }

            if (q.empty() && word == endWord) return level + 1;
        }

        return 0;
    }
};

int main(){
    Solution sol;
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    string beginWord = "hit", endWord = "cog";

    cout << sol.ladderLength(beginWord, endWord, wordList);
    return 0;
}