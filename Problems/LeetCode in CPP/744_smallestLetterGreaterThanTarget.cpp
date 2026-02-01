#include<iostream>
#include<vector>
using namespace std;

// O(n) solution

// class Solution {
// public:
//     char nextGreatestLetter(vector<char>& letters, char target) {
//         if (target >= letters[letters.size()-1]) return letters[0];
//         for (const char& c : letters){
//             if (c > target) return c;
//         }
//         return '0';
//     }
// };


// O(log n) solution

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();

        if (target >= letters[n - 1]) return letters[0];

        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (letters[mid] > target) {
                right = mid - 1;   
            } else {
                left = mid + 1;    
            }
        }

        return letters[left];
    }
};


int main(){
    Solution sol;
    // vector<char> letters = {'x','x','y','y'}; char target = 'z';
    // vector<char> letters = {'c', 'f', 'j'}; char target = 'f';
    vector<char> letters = {'c', 'f', 'j', 'm', 'o', 'x'}; char target = 'd';

    cout << sol.nextGreatestLetter(letters, target) << endl;

    return 0;
}