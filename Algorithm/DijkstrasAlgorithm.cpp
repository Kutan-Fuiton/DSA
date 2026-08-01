// Dijkstra's algorithm

// Dijkstra(Graph G, Source S)
// 1. Set distance of every vertex = ∞
// 2. Set distance[S] = 0
// 3. Mark all vertices as unvisited.
// 4. While there are unvisited vertices:
//       a. Pick the unvisited vertex with the smallest distance.
//       b. Mark it as visited.
//       c. For every unvisited neighbor:
//              newDist = distance[current] + edgeWeight
//              if newDist < distance[neighbor]:
//                     distance[neighbor] = newDist
//                     previous[neighbor] = current
// 5. Return the distance[] and previous[] arrays.




/*  DJikstra's workflow:-


        A
       / \
    8 /   \ 2
     /     \
    D-------B
    |\  5   |
    | \     |
  2 |  \    |6
    |   \3  |
    |    \  |
    |     \ |
    |   1  \|
    F-------E
     \     /
     3\   /9
       \ /
        C

This is the given graph...
let the Nodes are {A, B, C, D, E, F} equivalent to their index positions from 0 - 5

## Initialisation:- 
distance vector = {INF, INF, INF, INF, INF, INF}
visited vector = {F, F, F, F, F, F}   --> boolean vector
parent vector = {-1, -1, -1, -1, -1, -1}    --> to track off the shortest path in the algorithm


## Iteration 1 (Only source A has distance 0):- 
dist = {0, INF, INF, INF, INF, INF}
visited = {F, F, F, F, F, F}
parent = {-1, -1, -1, -1, -1, -1}

## We need to process all vertices, so a loop will run from 0 to V-2 inclusive...
current = -1
minDist = INF or INT_MAX

## First Relaxation for all Vertices (Run a loop for all vertices from 0 to V-1):-

### if the vertices is not visited and its distance is less than minDist
then make the minDist = its distance and set current to that vertices

like, for example, every vertices initially have not visited and every distance is INF which is not less than INF except source which has distance 0
So for source A, minDist = its distance and current set to source A

now after the loop, mark the current node as visited which is the source node

### now relax all the neighbors of current node (source node) A (run a loop for all the nodes in case of adjacency matrix neighbor finding)
--> graph[current][neighbor] = 0 those are not edges, so we will skip those
--> those neighbor which are already visited, we will skip those too
--> calculate the new possible distance, newDist = (dist of current node) + (weight of the edge from current to neighbor)
--> Relaxation, if shorter path found, if newDist < dist of neighbor
                then dist of neighbor will be updated and become newDist and parent of neighbor will become current

That's it, we will get the shortest distance and 
*/


// SOURCE CODE:-
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// Structure is so that we can get both dijkstra's shortest path value and the particular path too...
struct DijkstraResult {
    vector<int> dist;
    vector<int> parent;
};

// If the source is C in A, B, C, D, C, E, F, then int source will be 2
DijkstraResult dijkstra(vector<vector<int>>& graph, int source){
    int N = graph.size(); // no of nodes in graph
    int INF = INT32_MAX;

    // Initialisation
    vector<int>  dist      (N, INF);
    vector<bool> visited   (N, 0);
    vector<int>  parent    (N, -1);

    // Source Distance Initialisation
    dist[source] = 0;

    // Lambda to find the unvisited vertex with the minimum distance
    auto findMinimumDistanceVertex = [&]() -> int {
        int current = -1;
        int minDist = INF;

        for (int i = 0; i < N; i++){
            if (!visited[i] && dist[i] < minDist){
                minDist = dist[i];
                current = i;
            }
        }

        return current;
    };

    // Lambda to relax all neighbours of the current vertex
    auto relaxNeighbours = [&](int current) -> void {
        for (int neighbour = 0; neighbour < N; neighbour++){
            // If no edge exist with that neighbor then skip
            if (graph[current][neighbour] == 0) continue; 

            // If neighbor visited then skip
            if (visited[neighbour]) continue;

            if (dist[current] == INT32_MAX) continue;

            int newDist = dist[current] + graph[current][neighbour];

            if (newDist < dist[neighbour]){
                dist[neighbour] = newDist;
                parent[neighbour] = current;
            }
        }
    };

    // Main Dijsktra's loop
    while (true){
        int current = findMinimumDistanceVertex();
        if (current == -1) break;     // If no reachable node exists

        visited[current] = true;

        relaxNeighbours(current);
    }

    return {dist, parent};
}

// Shortest Distance Value between source and destination
int getDijkstraShortestDist(vector<vector<int>>& graph, int source, int destination){
    auto res = dijkstra(graph, source);
    return res.dist[destination];
}

// Shortest Path between source and destination
vector<int> getDijkstraShortestPath(vector<vector<int>>& graph, int source, int destination) {
    auto res = dijkstra(graph, source);

    vector<int> path;

    // No path exists
    if (res.dist[destination] == INT32_MAX) return path;

    // Start from destination and follow parents back to source
    int current = destination;

    while (current != -1){
        path.push_back(current);
        current = res.parent[current];
    }

    // Reverse to get source -> destination
    reverse(path.begin(), path.end());

    return path;
}

int main() {
    vector<vector<int>> graph = {
    //   0  1  2  3  4  5
        {0, 4, 2, 0, 0, 0}, // 0
        {4, 0, 1, 5,10, 0}, // 1
        {2, 1, 0, 0, 3, 0}, // 2
        {0, 5, 0, 0, 2, 2}, // 3
        {0,10, 3, 2, 0, 4}, // 4
        {0, 0, 0, 2, 4, 0}  // 5
    };

    int source =        0;
    int destination =   5;

    cout << "The Shortest Distance between " << source << " and " << destination << " is " << getDijkstraShortestDist(graph, source, destination) << endl;


    vector<int> path = getDijkstraShortestPath(graph, source, destination);

    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size()-1) cout << "-->";
    }
    cout << endl;

    return 0;
}

