#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<long long> distance(vector<int> &nums){
        unordered_map<int, vector<int>> map;

        for (int i = 0; i < nums.size(); i++) map[nums[i]].push_back(i);

        vector<long long> res(nums.size(), 0);
        for (auto &it : map){
            vector<int> &idx = it.second;
            int n = idx.size();

            vector<long long> pre(n, 0);
            pre[0] = idx[0];

            for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + idx[i];

            for (int i = 0; i < n; i++)
            {
                long long left = 0, right = 0;

                if (i > 0) left = (long long)idx[i] * i - pre[i - 1];
                if (i < n - 1) right = (pre[n - 1] - pre[i]) - (long long)idx[i] * (n - i - 1);

                res[idx[i]] = left + right;
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 3, 1, 1, 2};

    vector<long long> ans = sol.distance(nums);
    for (const int n : ans)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}