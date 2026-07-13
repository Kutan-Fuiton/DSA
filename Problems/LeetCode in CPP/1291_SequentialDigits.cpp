#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string temp = "123456789";
        vector<int> arr;
        
        int min_len = to_string(low).length();
        int max_len = to_string(high).length();
        
        for (int i = min_len; i <= max_len; i++) {
            for (int j = 0; j <= 9 - i; j++) {
                int num = stoi(temp.substr(j, i));
                
                if (num >= low && num <= high) arr.push_back(num);
            }
        }
        
        return arr;
    }
};

int main(){
    Solution sol;
    vector<int> op = sol.sequentialDigits(1000, 13000);
    for (int i = 0; i < op.size(); i++){
        cout << op[i] << " ";
    }
    cout << endl;
    return 0;
}