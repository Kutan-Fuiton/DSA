#include<iostream>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int count = 0, res = 0;
        for (char c : customers){
            if (c == 'Y') count++;
        }
        int min_count = count;
        for (int j = 1; j <= customers.size(); j++){
            if (customers[j-1] == 'Y') count--;
            if (customers[j-1] == 'N') count++;
            if (min_count > count) {min_count = count; res = j;}
        }
        return res;
    }
};

int main(){
    Solution sol;
    string n = "NYNYYNNY";

    cout << sol.bestClosingTime(n) << endl;

    return 0;
}