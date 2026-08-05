#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Adjacency List Creation
        vector<pair<int, int>> graph[n + 1];
        for (auto& edge : times){
            graph[edge[0]].push_back({edge[1], edge[2]});
        }

        // Will apply dijkstra's algorithm
        // Distance vector initialised to infinity
        const int INF = 1e9;
        vector<int> dist(n+1, INF);
        dist[k] = 0;

        // min heap priority queue storing {distance so far, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        min_heap.push({0, k});

        // Process the Min-Heap
        while (!min_heap.empty()) {
            pair<int, int> top = min_heap.top();
            int current_time = top.first;
            int u = top.second;
            min_heap.pop();

            if (current_time > dist[u]) continue;

            // Relaxation of all outgoing edges from node u
            for (const auto& neighbor : graph[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (current_time + weight < dist[v]) {
                    dist[v] = current_time + weight;
                    min_heap.push({dist[v], v});
                }
            }
        }

        // maximum time needed (max time for min heap is minimum only)
        int max_time = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF) return -1; // node is not reachable
            max_time = max(max_time, dist[i]);
        }

        return max_time;
    }
};



int main(){
    Solution sol;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}}; int n = 4, k = 2;

    cout << sol.networkDelayTime(times, n, k) << endl;
    return 0;
}