#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0; 
        for (int i = 1; i < points.size(); i++){
            int x = abs(points[i][0] - points[i-1][0]);
            int y = abs(points[i][1] - points[i-1][1]);
            time += max(x,y);
        }
        return time;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> points = {
        {1,1},
        {3,4},
        {-1,0}
    };

    cout << sol.minTimeToVisitAllPoints(points) << endl;

    return 0;
}