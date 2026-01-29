#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;
        while (low <= high) {
            int i = (low + high) / 2;                 
            int j = (m + n + 1) / 2 - i;  
            int l1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int R1 = (i == m) ? INT_MAX : nums1[i];
            int l2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int R2 = (j == n) ? INT_MAX : nums2[j];

            if (l1 <= R2 && l2 <= R1) {
                if ((m + n) % 2 == 0) {
                    return (max(l1, l2) + min(R1, R2)) / 2.0;
                } else {
                    return max(l1, l2);
                }
            } else if (l1 > R2) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }
        return 0.0; 
    }
};

int main(){
    Solution sol;
    vector<int> nums1 = {1,7,11,19,23};
    vector<int> nums2 = {4,6,12,24};

    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}