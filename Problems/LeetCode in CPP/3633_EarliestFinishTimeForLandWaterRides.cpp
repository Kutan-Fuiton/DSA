#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int end = INT32_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Land first, then water
                int landFinish = landStartTime[i] + landDuration[i];
                int total1 = max(landFinish, waterStartTime[j]) + waterDuration[j];
                
                // Water first, then land
                int waterFinish = waterStartTime[j] + waterDuration[j];
                int total2 = max(waterFinish, landStartTime[i]) + landDuration[i];
                
                end = min(end, min(total1, total2));
            }
        }
        return end;
    }
};

int main(){
    Solution sol;
    vector<int> landStartTime = {2,8}; vector<int> landDuration = {4,1}; vector<int> waterStartTime = {6}; vector<int> waterDuration = {3};

    cout << sol.earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration) << endl;

    return 0;
}