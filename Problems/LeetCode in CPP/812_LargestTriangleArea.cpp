#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {

                    double area = abs(
                        points[i][0] * (points[j][1] - points[k][1]) +
                        points[j][0] * (points[k][1] - points[i][1]) +
                        points[k][0] * (points[i][1] - points[j][1])
                    ) / 2.0;

                    ans = max(ans, area);
                }
            }
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> points = {{0,0}, {0,1}, {1,0}, {0,2}, {2,0}};

    cout << sol.largestTriangleArea(points) << endl;

    return 0;
}