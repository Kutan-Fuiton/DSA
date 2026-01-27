#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int MAX = -1;
        vector<int> res = {-1, -1};

        for (int i = 0; i < towers.size(); i++) {
            int x = towers[i][0];
            int y = towers[i][1];
            int q = towers[i][2];

            int dist = abs(x - center[0]) + abs(y - center[1]);
            if (dist > radius) continue;

            if (q > MAX) {
                MAX = q;
                res = {x, y};
            }
            else if (q == MAX) {
                if (x < res[0] || (x == res[0] && y < res[1])) {
                    res = {x, y};
                }
            }
        }
        return res;
    }
};


int main(){
    Solution sol;
    vector<vector<int>> towers = {{1,2,5}, {2,1,7}, {3,1,9}};
    vector<int> center = {1,1}; int radius = 2; 


    vector<int> res = sol.bestTower(towers, center, radius);

    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}