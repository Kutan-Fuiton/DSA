// As we have to know the longest consecutive sequence in O(n) time complexity
// We will insert all the elements in a hash set, it will deduct the duplicates which is ofc no need here
// now processing each number in nums array, and check whether nums[i]-1 exist in set or not
// if exist, that means the sequence will not start from there, so skip that iteration
// will do action for that number, whose prev num doesnt exists
// so after getting the number will start interior loop, to see next till which elements exits, and save in longCon
// currCon is for streak for each element... 
// that is how we will get the longest Consecutive sequence...

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nmset(nums.begin(), nums.end());

        int longCon = 0;

        for (const int nm : nmset){ 
            if (nmset.count(nm - 1) == 0){
                int curr = nm;
                int currCon = 1;

                while (nmset.count(curr + 1)){
                    curr++;
                    currCon++;
                }

                longCon = max(longCon, currCon);
            }
        }

        return longCon;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};

    cout << sol.longestConsecutive(nums) << endl;

    return 0;
}