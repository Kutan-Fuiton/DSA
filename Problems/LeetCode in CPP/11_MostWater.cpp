#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int MAX = 0;
        while (i < j) {
            int h = min(height[i], height[j]);
            int width = j - i;
            MAX = max(MAX, h * width);

            if (height[i] < height[j]) i++;
            else j--;
        }
        return MAX;
    }
};

int main(){
    Solution sol;

    vector<int> height = {1,8,6,2,5,4,8,3,7};

    cout << sol.maxArea(height) << endl;

    return 0;
}