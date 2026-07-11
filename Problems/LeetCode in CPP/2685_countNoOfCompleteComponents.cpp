#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;

    void dfs(int node, int &nodes, int &degreeSum) {
        vis[node] = true;
        nodes++;
        degreeSum += adj[node].size();

        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                dfs(neigh, nodes, degreeSum);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        vis.assign(n, false);

        // Build graph
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nodes = 0;
                int degreeSum = 0;

                dfs(i, nodes, degreeSum);

                int edgeCount = degreeSum / 2;
                int requiredEdges = nodes * (nodes - 1) / 2;

                if (edgeCount == requiredEdges) ans++;
            }
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {3, 4}
    };

    cout << sol.countCompleteComponents(6, edges) << endl;
    return 0;
}