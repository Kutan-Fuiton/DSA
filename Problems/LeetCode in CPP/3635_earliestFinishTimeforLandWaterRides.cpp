#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    long long earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        long long minLandFinish = LLONG_MAX;
        long long minWaterFinish = LLONG_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        // Earliest possible land ride completion
        for (int i = 0; i < n; i++) {
            minLandFinish = min(minLandFinish, (long long)landStartTime[i] + landDuration[i]);
        }

        // Earliest possible water ride completion
        for (int j = 0; j < m; j++) {
            minWaterFinish = min(minWaterFinish, (long long)waterStartTime[j] + waterDuration[j]);
        }

        long long ans = LLONG_MAX;

        // Land -> Water
        for (int j = 0; j < m; j++) {
            long long finishTime = max(minLandFinish, (long long)waterStartTime[j]) + waterDuration[j];

            ans = min(ans, finishTime);
        }

        // Water -> Land
        for (int i = 0; i < n; i++) {
            long long finishTime = max(minWaterFinish, (long long)landStartTime[i]) + landDuration[i];

            ans = min(ans, finishTime);
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> landStartTime = {2,8}; vector<int> landDuration = {4,1}; vector<int> waterStartTime = {6}; vector<int> waterDuration = {3};

    cout << sol.earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration) << endl;

    return 0;
}