#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int MAX = 0;
        while (i < nums1.size()){
            MAX = max(MAX, binSearch(nums2, nums1[i], i));
            i++;
        }
        return MAX;
    }

private:
    int binSearch(vector<int>& arr, int key, int idx){
        int low = 0; 
        int high = arr.size() - 1;
        int MAX = 0;
        
        while (low <= high){
            int mid = low + (high-low)/2;
            if (key <= arr[mid]) {
                MAX = max(MAX, mid - idx);
                low = mid+1;
            }
            else high = mid-1;
        }
        return MAX;
    }
};

int main(){
    Solution sol;
    vector<int> nums1 = {55,30,5,4,2}; vector<int> nums2 = {100,20,10,10,5};
    // vector<int> nums1 = {2,2,2}; vector<int> nums2 = {10,10,1};

    cout << sol.maxDistance(nums1, nums2) << endl;

    return 0;
}