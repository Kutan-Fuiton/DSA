#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for (int hour = 0; hour < 12; hour++) {
            for (int minute = 0; minute < 60; minute++) {
                int totalBits = __builtin_popcount(hour) + __builtin_popcount(minute);  // return the no of 1s in it... 

                if (totalBits == turnedOn) {
                    string time = to_string(hour) + ":";
                    if (minute < 10) time += "0";
                    time += to_string(minute);
                    result.push_back(time);
                }
            }
        }

        return result;
    }
};

int main(){
    Solution sol;
    vector<string> res = sol.readBinaryWatch(1);

    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}