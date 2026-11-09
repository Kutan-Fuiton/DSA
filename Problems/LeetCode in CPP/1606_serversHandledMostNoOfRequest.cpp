#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();

        // busy is a min heap, which contains (end_time, server_id) of all busy servers...
        // Initially all servers will be free so no busy servers...
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;

        // maintain the availability of servers in sorted order, so that we can get the element by lower_bound
        // initially all servers will be free, so every k servers will be available...
        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }

        // We need to maintaing a request_count of each servers
        vector<int> count(k);


        for (int i = 0; i < n; i++){
            long long time = arrival[i];

            // release all servers that finished before or at current arrival time
            while (!busy.empty() && busy.top().first <= time) {
                available.insert(busy.top().second);
                busy.pop();
            }

            // if available is empty, that means no server available the current request is blocked, so move to next request
            if (available.empty()) continue;

            // Find the target server which is available for now from available servers
            // lower_bound function, it will find the target which is (i%k), if we can't find that, it will go for the greater than target
            // That is why we used set for sorted, so that if we cant get the target, we will find for next index
            auto it = available.lower_bound(i%k);

            // now when we try to find the next greater element, if we cant find anything greater then lower bound returns to the end,
            // but in the problem, it stated that, if target exceeds the last index, then we can go back reset from 0
            // and while traversing available set, the next available after the end element will be the begin element ofc.
            // so we will initiate the wrap around condition which is
            if (it == available.end()) it = available.begin();

            // Now we got the iterator of that server, now dereference it to get the server id and erases it from the available set making it busy.
            int server_id = *it;
            available.erase(server_id);

            // Now as we delete the server from available, have to include it in busy min heap too...
            busy.push({time + load[i], server_id});
            count[server_id]++;
        }


        // Calculating the max count elements
        int max_requests = *max_element(count.begin(), count.end());
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            if (count[i] == max_requests) {
                res.push_back(i);
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> arrival = {1,2,3,4,5};
    vector<int> load = {5,2,3,3,3};

    vector<int> res = sol.busiestServers(3, arrival, load);
    for (const int num : res){
        cout << num << " ";
    }cout << endl;

    return 0;
}