#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Graph {
private:
    int V;                        // No of nodes in graph
    bool directed;                // Is the graph directed or undirected?
    vector<vector<int>> adj;      // Adjacency matrix for the graph

public:
    // Constructor
    Graph(int nodes, bool isDirected = false){
        V = nodes;
        directed = isDirected;
        adj.resize(V);
    }

    // Adding Edge Function
    void addEdge(int u, int v){
        adj[u].push_back(v);
        if (!directed) adj[v].push_back(u);
    }

    // Removing Edge Function
    void removeEdge(int u, int v) {
        auto &a = adj[u];
        a.erase(remove(a.begin(), a.end(), v), a.end());

        if (!directed) {
            auto &b = adj[v];
            b.erase(remove(b.begin(), b.end(), u), b.end());
        }
    }

    // Get neighbors
    vector<int> getNeighbors(int u) { return adj[u]; }
    
    // No of vertices
    int size() { return V; }
    
    // Access adjacency list
    vector<vector<int>>& getAdjList() { return adj; }
    
    // Print graph
    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int neighbor : adj[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

// This class can initiate adjacency matrix graph, add edges, remove edges and print them and several function

// Remove Erase Combination. How it works?
// ans:- remove(a.begin(), a.end(), v) --> It will scan whole container a from begin to end for the element v and then will remove the element and then will shift all the rest of the elements to the front of the container to cover up space. It returns a pointer to new logical end instead of old end... Now from new end to old end, there are no elements, so it considered as garbage, so we will erase those space from memory by doing .erase(new end, old end)... where new end means remove(a.begin(), a.end(), v) this one...
