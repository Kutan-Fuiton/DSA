#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();

        // By using 2D Dynamic Programming Method (Create a DP of n+1 X m+1 size)
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));

        // The question: In how many ways of subsequences of string s, we can form string t

        // base condition: setting the first row and first column

        // What first column means? dp[i][0] ==> (string s is of length 0 to n) and (string t is of length 0)
        // if string t is empty string, then there is only one way to form the string, which is deleting all elements of string s
        // so dp[i][0] = 1 (Always) for i from 0 to n
        for (int i = 0; i <= n; ++i) dp[i][0] = 1;
        
        // What first row means? dp[0][j] ==> (String s is of length 0) and (String t is of length 1 to n)
        // if string s is empty, then its impossible to form string t of some length because there is no elements in string s
        // so dp[0][j] = 0 (Always) for j from 1 to n

        // Now the transition condition: setting (i,j) element; where (i and j) >= 1
        // If ith character of string s does not match with jth character of string t (s[i] != t[j]) => dp[i-1][j]
        // then that means we will skip that character, and will check the prefix of string s with current t
        
        // If ith character of string s matches with jth character of string t (s[i] == t[j]) => dp[i-1][j-1] + dp[i-1][j]
        // then there can be two possibility we can do: 
        // 1. accept the ith character to form the complete t at the end: It will reduce the problem a little bit, then i have to care about finding characters in the prefix of s with the prefix of t, that means dp[i-1][j-1]
        // 2. skip the ith character to search for better character to complete t at the end: It will just skip the character, then i will just care about other characters in s to fulfill t, that means dp[i-1][j]

        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j){
                dp[i][j] = dp[i-1][j];
                if (s[i-1]==t[j-1]) dp[i][j]+=dp[i-1][j-1];
            }
        }

        return (int)dp[n][m];
    }
};

int main(){
    Solution sol;
    cout << sol.numDistinct("rabbbit", "rabbit") << endl;
    return 0;
}