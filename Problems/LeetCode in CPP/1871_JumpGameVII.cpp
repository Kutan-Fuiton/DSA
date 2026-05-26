#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        
        int n = s.size();

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(0);
        vis[0] = true;

        // tracks how far we've already scanned
        int farthest = 0;

        while (!q.empty()) {

            int idx = q.front();
            q.pop();

            int left = max(idx + minJump, farthest + 1);
            int right = min(idx + maxJump, n - 1);

            for (int j = left; j <= right; j++) {

                if (!vis[j] && s[j] == '0') {

                    if (j == n - 1) return true;

                    vis[j] = true;
                    q.push(j);
                }
            }

            // basically, by doing this, we not waste time in previous steps limit range
            // for example imagine, if 0 index cover 2 -> 4 indexes and 1 index cover 3 -> 6 index
            // then while visiting valid steps for index 1, we will check for 5 -> 6 cuzz 3 -> 4 will get check already
            // avoiding steps
            farthest = right;
        }

        return n == 1;
    }
};

int main(){
    Solution sol;

    cout << sol.canReach("011010", 2, 3) << endl;

    return 0;
}