#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> set;

        for (auto &obs : obstacles) {
            long long key = ((long long)obs[0] << 32) | (obs[1] & 0xffffffff);
            set.insert(key);
        }

        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1},{-1,0}};
        int d = 0; // north facing

        int x = 0, y = 0;
        int MAX = 0;

        for (int cmd : commands) {
            if (cmd == -1) d = (d+1)%4;  // imagine rotating clockwise 1 quarter from north --> left
            else if (cmd == -2) d = (d+3)%4;  // imagine rotating clockwise 3 quarter from north --> right
            else {
                int dx = dirs[d].first;
                int dy = dirs[d].second;
                while (cmd--){
                    int nx = x + dx;
                    int ny = y + dy;

                    long long key = ((long long)nx << 32) | (ny & 0xffffffff);

                    if (set.count(key)) break;

                    x = nx; y = ny;

                    MAX = max(MAX, x*x + y*y);
                }
            }
        }

        return MAX;
    }
};

int main(){
    Solution sol;
    vector<int> commands = {4,-1,4,-2,4};
    vector<vector<int>> obstacles = {{2,4}};

    cout << sol.robotSim(commands, obstacles) << endl;

    return 0;
}