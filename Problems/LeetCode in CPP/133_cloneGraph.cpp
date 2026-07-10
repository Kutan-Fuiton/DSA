#include<iostream>
#include<vector>
#include<algorithm>

#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

void printGraphWithArrows(Node* startNode) {
    if (startNode == nullptr) {
        cout << "Empty Graph" << endl;
        return;
    }

    unordered_set<Node*> visited;
    queue<Node*> q;

    q.push(startNode);
    visited.insert(startNode);

    cout << "\n--- Graph Visual Representation ---" << endl;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        // Print the source node
        cout << curr->val;

        // Print arrows to all its neighbors
        if (curr->neighbors.empty()) {
            cout << " -> DNE (Does not exit/No neighbors)";
        } else {
            for (Node* neighbor : curr->neighbors) {
                cout << " -> " << neighbor->val;

                // Add unvisited neighbors to the queue
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> mp;

        queue<Node*> q;

        mp[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()){
            Node* curr = q.front();
            q.pop();

            for (Node* neighbor : curr->neighbors){
                if (mp.find(neighbor) == mp.end()){
                    mp[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                mp[curr]->neighbors.push_back(mp[neighbor]);
            }
        }

        return mp[node];
    }
};

int main(){
    Solution sol;

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors = {node2, node3};  
    node2->neighbors = {node4};       
    node3->neighbors = {node4};         
    node4->neighbors = {node1}; 

    cout << "previously" << endl;
    printGraphWithArrows(node1);
    cout << endl;
    
    Node* op = sol.cloneGraph(node1);

    cout << "currently" << endl;
    printGraphWithArrows(node1);
    cout << endl;

    return 0;
}