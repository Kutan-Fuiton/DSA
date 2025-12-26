#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        if (k == 0) return 0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long sum = 0;
        for (int i = 0; i < k && i < happiness.size(); i++){
            sum += (long long)max(0, happiness[i] - i);
        }
        return sum;
    }
};

int main(){
    Solution sol;
    vector<int> happiness = {INT32_MAX, INT32_MAX, INT32_MAX};
    int k = 3;

    cout << sol.maximumHappinessSum(happiness, k) << endl;

    return 0;
}