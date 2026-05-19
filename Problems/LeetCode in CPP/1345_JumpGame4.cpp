#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;

        for(int i=0;i<n;i++)
            mp[arr[i]].push_back(i);

        queue<int> q;
        vector<int> vis(n,false);

        q.push(0);
        vis[0] = true;

        int steps = 0;

        while(!q.empty()) {

            int sz = q.size();

            while(sz--) {

                int i = q.front();
                q.pop();

                if(i == n-1)
                    return steps;

                // i-1
                if(i - 1 >= 0 && !vis[i - 1]) {
                    vis[i - 1] = true;
                    q.push(i - 1);
                }

                // i+1
                if(i + 1 < n && !vis[i + 1]) {
                    vis[i + 1] = true;
                    q.push(i + 1);
                }

                // same value jumps
                for(int idx : mp[arr[i]]) {
                    if(!vis[idx]) {
                        vis[idx] = true;
                        q.push(idx);
                    }
                }

                // to clear the visited one, to not approach O(n^2)
                mp[arr[i]].clear();
            }

            steps++;
        }

        return steps;
    }
};

int main(){
    Solution sol;
    vector<int> arr1 = {100,-23,-23,404,100,23,23,23,3,404};
    vector<int> arr2 = {7,6,9,6,9,6,9,7};
    vector<int> arr3 = {7};

    cout << sol.minJumps(arr1) << endl;
    cout << sol.minJumps(arr2) << endl;
    cout << sol.minJumps(arr3) << endl;
    return 0;
}