#include<iostream>
#include<vector>
#include<cmath> // abs() function
using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        int M = 0; 
        long long k = (long long) k1+k2; 
        long long sum = 0;

        vector<int> diff(n);

        for (int i = 0; i < n; ++i) {
            int absDiff = abs(nums1[i] - nums2[i]);
        
            M = max(M, absDiff);
            diff[i] = absDiff;
            sum += absDiff;
        }

        if (k >= sum) return 0;

        vector<int> count(M+1, 0);

        for (int i = 0; i < n; ++i) count[diff[i]]++;

        for (int v = M; v >= 1 && k != 0; --v){
            long long dec = min(k, (long long) count[v]);
            count[v] -= dec;
            count[v-1] += dec;
            k -= dec;
        }

        // calculate sum of squared diff left in count array
        long long ans = 0;
        for (long long v = 1; v <= M; ++v){
            if (count[v] > 0) ans += (long long) count[v] * v * v;
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums1 = {1,2,3,4}; vector<int> nums2 = {2,10,20,19};

    cout << sol.minSumSquareDiff(nums1, nums2, 0, 0) << endl;
    return 0;
}