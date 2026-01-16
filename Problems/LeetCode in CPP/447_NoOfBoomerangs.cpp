#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 3) return 0;

        int res = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int d = distance(points[i], points[j]);
                freq[d]++;
            }

            for (auto &it : freq) {
                int m = it.second;
                res += m * (m - 1);
            }
        }

        return res;
    }

private:
    int distance(vector<int>& p1, vector<int>& p2) {
        int dx = p2[0] - p1[0];
        int dy = p2[1] - p1[1];
        return dx * dx + dy * dy;  // squared distance
    }
};


int main(){
    Solution sol;
    // vector<vector<int>> points = {{0,0}, {1,0}, {2,0}};
    vector<vector<int>> points = {{1,1}, {2,2}, {3,3}};
    // vector<vector<int>> points = {{1,1}};

    cout << sol.numberOfBoomerangs(points) << endl;
    // cout << sol.distance(points[0], points[2]) << endl;

    return 0;
}