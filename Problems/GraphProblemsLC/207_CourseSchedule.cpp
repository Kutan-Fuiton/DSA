#include<iostream>
#include<vector>
#include <unordered_map>
#include <string>
using namespace std;

class Graph {
    unordered_map<int, vector<int>> adjList;

public:
    void addEdge(int u, int v, bool isDirected = false) {
        adjList[u].push_back(v);
        
        if (!isDirected) {
            adjList[v].push_back(u);
        }
    }

    void printGraph() {
        for (const auto& pair : adjList) {
            const auto& node = pair.first;
            const auto& neighbors = pair.second;

            cout <<  node << " --> ";
            for (const int& neighbor : neighbors) {
                cout << neighbor << " ";
            }
            cout << "\n";
        }
    }
};

// Expected Adjancecy List for this test case will be
// 0 -> [1]
// 1 -> [2, 4]
// 2 -> [3]
// 3 -> [5]
// 4 -> [5]
// 5 -> [2]

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> g;   // graph made by adjancency list

        // graph initiating
        for (const auto& pair : prerequisites){
            g[pair[1]].push_back(pair[0]);
        }

        // state: 0 = unvisited, 1 = visiting, 2 = visited
        std::vector<int> state(numCourses, 0);
        
        // Lambda DFS function
        auto hasCycle = [&](auto& self, int node) -> bool {
            state[node] = 1; // Mark as visiting(1)
            
            for (int neighbor : g[node]) {
                if (state[neighbor] == 1) {
                    return true; // Cycle detected
                }
                if (state[neighbor] == 0) {
                    if (self(self, neighbor)) return true;
                }
            }
            
            state[node] = 2; // Mark as visited
            return false;
        };
        
        // DFS for every component
        for (int i = 0; i < numCourses; ++i) {
            if (state[i] == 0) {
                if (hasCycle(hasCycle, i)) return false;
            }
        }
        
        return true;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> edges = {{1, 0}, {2, 1}, {3, 2}, {4, 1}, {5, 3}, {5, 4}, {2, 5}};
    
    // Graph g;
    
    // for (const auto& pair : edges){
    //     g.addEdge(pair[1], pair[0], true);
    // }

    // g.printGraph();

    cout << sol.canFinish(6, edges) << endl;

    return 0;
}