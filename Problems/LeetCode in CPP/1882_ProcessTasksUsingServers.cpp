#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        // min heap for available servers: {weight, server_id}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free_servers;
        for (int i = 0; i < n; ++i) {
            free_servers.push({servers[i], i});
        }

        // min heap for occupied servers: {free_time, server_id}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy_servers;

        vector<int> res(m);
        long long current_time = 0;

        for (int i = 0; i < m; ++i) {
            current_time = max(current_time, static_cast<long long>(i));

            // ff all servers are occupied, fast forward time to the next completion
            if (free_servers.empty()) {
                current_time = max(current_time, busy_servers.top().first);
            }

            // free all servers that finished at or before current_time
            while (!busy_servers.empty() && busy_servers.top().first <= current_time) {
                int server_id = busy_servers.top().second;
                busy_servers.pop();
                free_servers.push({servers[server_id], server_id});
            }

            // assign the lowest weight (and lowest index) server
            auto firstelem = free_servers.top();
            int weight = firstelem.first;
            int server_id = firstelem.second;

            free_servers.pop();

            res[i] = server_id;
            busy_servers.push({current_time + tasks[i], server_id});
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> servers = {3,3,2};
    vector<int> task = {1,2,3,2,1,2};

    vector<int> res = sol.assignTasks(servers, task);
    for (const int num : res){
        cout << num << " ";
    }cout << endl;

    return 0;
}