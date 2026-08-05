#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Building adjacency list
        vector<vector<int>> adj(n);
        for (const auto& pair : invocations) {
            adj[pair[0]].push_back(pair[1]);
        }

        // mark suspicious methos using BFS
        vector<bool> is_sus(n, false);
        queue<int> q;

        q.push(k);
        is_sus[k] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (!is_sus[v]) {
                    is_sus[v] = true;
                    q.push(v);
                }
            }
        }

        // sus calling non sus makes both sus and both removable
        // sus calling sus makes boths sus and both removable
        // non sus calling non sus makes both non sus and both stays
        // but non sus calling sus makes it stays, because code will break if sus removed (so we will handle this case isolately)

        // checking for non suspicious to suspicious invocation
        for (const auto& pair : invocations) {
            int u = pair[0];
            int v = pair[1];

            // If a clean method calls a suspicious method, we cannot remove anything
            if (!is_sus[u] && is_sus[v]) {
                vector<int> all_methods(n);
                for (int i = 0; i < n; i++) {
                    all_methods[i] = i;
                }
                return all_methods;
            }
        }

        // normally, only takes non sus elements in an array
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (!is_sus[i]) {
                res.push_back(i);
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> invocations = {{1,2},{0,2},{0,1},{3,4}};

    vector<int> res = sol.remainingMethods(5, 0, invocations);
    for (int num : res){
        cout << num << " ";
    } cout << endl;
    return 0;
}