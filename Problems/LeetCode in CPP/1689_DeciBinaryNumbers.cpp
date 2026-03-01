#include<iostream>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int MAX = 0;
        for (const char& ch : n){
            MAX = max(MAX, ch - '0');
        }
        return MAX;
    }
};

int main(){
    Solution sol;

    cout << sol.minPartitions("27346209830709182346") << endl;

    return 0;
}