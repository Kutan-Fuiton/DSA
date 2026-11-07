#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        int l_size = logs.size();

        // sorting logs with timestamps in increasing order
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        // storing the queries alongside their indices in another array
        vector<pair<int, int>> sorted_queries(m);
        for (int i = 0; i < m; i++) {
            sorted_queries[i] = {queries[i], i};
        }
        sort(sorted_queries.begin(), sorted_queries.end());

        vector<int> res(m);
        vector<int> freq(n + 1, 0);
        int active_servers = 0;

        int left = 0;
        int right = 0;

        // process each query in increasing time order
        for (int i = 0; i < m; i++) {
            int q_time = sorted_queries[i].first;
            int orig_idx = sorted_queries[i].second;

            // expand right boundary: add logs with time <= q_time
            while (right < l_size && logs[right][1] <= q_time) {
                int s_id = logs[right][0];
                if (freq[s_id] == 0) {
                    active_servers++;
                }
                freq[s_id]++;
                right++;
            }

            // shrink left boundary: remove logs with time < q_time - x
            while (left < l_size && logs[left][1] < q_time - x) {
                int s_id = logs[left][0];
                freq[s_id]--;
                if (freq[s_id] == 0) {
                    active_servers--;
                }
                left++;
            }

            // inactive servers = total servers - active servers
            res[orig_idx] = n - active_servers;
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> logs = {{1,3},{2,6},{1,5}};
    vector<int> queries = {10, 11};
    
    vector<int> res = sol.countServers(3, logs, 5, queries);
    for (const int n : res){
        cout << n << " ";
    } cout << endl;
    return 0;
}