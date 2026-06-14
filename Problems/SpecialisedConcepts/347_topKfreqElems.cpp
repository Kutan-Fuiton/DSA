// At first, create a hash map, and store the frequency of numbers as value and numbers as key -- TC: O(n) ; SC: O(n)
// then will apply bucket sort, to get first k most frequent elements -- TC: O(n) ; SC: O(n)

// In total, it will be -- TC: O(n) ; SC: O(n)



#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        // Storing frequencies in hash map
        for (int i = 0; i < n; i++){
            mp[nums[i]]++; 
        }

        // Create buckets of size n+1 
        vector<vector<int>> buckets(n + 1);

        // Loop through the map
        for (auto& pair : mp) {
            int num = pair.first;
            int freq = pair.second;
            buckets[freq].push_back(num);
        }

        // 3. Creating result vector
        vector<int> res;

        // Traversing from right to left 
        for (int i = n; i >= 0; i--){
            for (int num : buckets[i]) {
                res.push_back(num);
                if (res.size() == k) {
                    return res; // Stop immediately once we have k elements
                }
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,1,2,1,2,3,1,3,2}; int k = 2;

    vector<int> res = sol.topKFrequent(nums, k);
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }

    return 0;
}