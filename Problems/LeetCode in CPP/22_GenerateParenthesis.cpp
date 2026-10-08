#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";

        backtrack(res, curr, 0, 0, n);
        return res;
    }

private:
    void backtrack(vector<string>& result, string& curr, int open_count, int close_count, int n){
        // Base case: If length 2*n string formed
        if (curr.size() == 2*n){
            result.push_back(curr);
            return;
        }

        // Add '(' in one condition, if open_count < n
        if (open_count < n){
            curr.push_back('(');
            backtrack(result, curr, open_count+1, close_count, n);
            curr.pop_back(); 
        }

        // Add ')' in one condition, if close_count < open_count
        if (close_count < open_count){
            curr.push_back(')');
            backtrack(result, curr, open_count, close_count+1, n);
            curr.pop_back(); 
        }
    }
};

int main(){
    Solution sol;
    vector<string> arr = sol.generateParenthesis(4);

    for (const string s : arr){
        cout << s << " ";
    }
    return 0;
}