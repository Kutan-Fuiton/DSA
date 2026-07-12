#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        
        unordered_map<int, int> rankMap;
        int rank = 1;
        
        for (int num : sorted) {
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank;
                rank++; 
            }
        }
        
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = rankMap[arr[i]];
        }
        
        return arr;
    }
};

int main(){
    Solution sol;
    vector<int> inp = {40, 10, 20, 30};

    vector<int> oup = sol.arrayRankTransform(inp);
    for (int i = 0; i < oup.size(); i++){
        cout << oup[i] << " ";
    }
    return 0;
}