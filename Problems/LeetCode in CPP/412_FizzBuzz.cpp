#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; i++){
            if (i % 3 == 0 && i % 5 == 0) res.push_back("FizzBuzz");
            else if (i % 3 == 0) res.push_back("Fizz");
            else if (i % 5 == 0) res.push_back("Buzz");
            else res.push_back(to_string(i));
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<string> output = sol.fizzBuzz(15);

    for (int i = 0; i < output.size(); i++){
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}