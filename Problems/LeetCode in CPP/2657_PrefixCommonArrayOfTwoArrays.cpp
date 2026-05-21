#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> freq(n, 0);
        vector<int> ans(n, 0);
        
        int count = 0;

        for (int i = 0; i < n; i++){
            freq[A[i]-1]++;

            if (freq[A[i]-1] == 2) count++;
            
            freq[B[i]-1]++;
            
            if (freq[B[i]-1] == 2) count++;

            ans[i] = count;
        }

        return ans;
    }
};

int main(){
    Solution sol;

    vector<int> A = {1,3,2,4}; vector<int> B = {3,1,2,4};

    vector<int> C = sol.findThePrefixCommonArray(A, B);

    for (const int val : C){
        cout << val << " ";
    }

    return 0;
}