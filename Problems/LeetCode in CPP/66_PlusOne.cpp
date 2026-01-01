#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.back() >= 0 && digits.back() < 9){
            digits[digits.size()-1]++;
        } else {
            int i = digits.size()-1;
            while (i>=0){
                if (digits[i] != 9){
                    break;
                }
                i--;
            }
            if (i < 0){
                digits.insert(digits.begin(), 1);
                i++;
            } else {
                digits[i]++;
            }
            for (int j = i+1; j < digits.size(); j++){
                digits[j] = 0;
            }
        }
        return digits;
    }
};

int main(){
    Solution sol;
    vector<int> digits = {9, 9, 9};

    vector<int> res = sol.plusOne(digits);

    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    
    return 0;
}