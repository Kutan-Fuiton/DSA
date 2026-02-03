// we using multiset for this, because whenever u will insert elements in multiset, the element will automatically go to sorted place...

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<climits>
using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long base = nums[0];
        long long ans = LLONG_MAX;

        multiset<int> small, large; // small holds k-1 smallest
        long long sumSmall = 0;

        // first window
        for (int i = 1; i <= dist + 1; i++) {
            small.insert(nums[i]);
            sumSmall += nums[i];

            if ((int)small.size() > k - 1) {
                auto it = prev(small.end());
                sumSmall -= *it;
                large.insert(*it);
                small.erase(it);
            }
        }

        ans = base + sumSmall;

        // sliding windor
        for (int i = dist + 2; i < n; i++) {
            int out = nums[i - (dist + 1)];
            int in  = nums[i];

            // Remove outgoing
            auto itSmall = small.find(out);
            if (itSmall != small.end()) {
                sumSmall -= out;
                small.erase(itSmall);

                if (!large.empty()) {
                    auto it = large.begin();
                    sumSmall += *it;
                    small.insert(*it);
                    large.erase(it);
                }
            } else {
                auto itLarge = large.find(out);
                if (itLarge != large.end())
                    large.erase(itLarge);
            }

            // Insert incoming
            small.insert(in);
            sumSmall += in;

            if ((int)small.size() > k - 1) {
                auto it = prev(small.end());
                sumSmall -= *it;
                large.insert(*it);
                small.erase(it);
            }

            ans = min(ans, base + sumSmall);
        }

        return ans;
    }
};




int main(){
    Solution sol;
    // vector<int> nums = {1,3,2,6,4,2}; int k = 3, dist = 3;
    vector<int> nums = {10,1,2,2,2,1}; int k = 4, dist = 3;


    cout << sol.minimumCost(nums, k, dist) << endl;

    return 0;
}