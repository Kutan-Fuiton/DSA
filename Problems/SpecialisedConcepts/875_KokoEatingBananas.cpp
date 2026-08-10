#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Calculating maximum elements
        int low = 1, high = 0;
        for (const int pile : piles) high = max(high, pile);
        int ans = high;

        while (low <= high){
            int mid = low + (high-low)/2;

            if (canFinish(piles, h, mid)){   // that means in 'mid' speed it can be finished, so a minimum speed can be possible
                high = mid - 1;
                ans = mid;
            } else {                         // that means in 'mid' speed it can be finished, so speed needs to be increased
                low = mid + 1;
            }
        }

        return ans;

    }
private:
    int canFinish(vector<int>& piles, int h, int k){
        long long totalHours = 0;
        for (int pile : piles){
            totalHours += (pile + k - 1)/k;
        }
        return (totalHours <= h);
    }
};

int main(){
    Solution sol;
    vector<int> piles = {30,11,23,4,20}; int h = 6;
    cout << sol.minEatingSpeed(piles, h) << endl;
    return 0;
}