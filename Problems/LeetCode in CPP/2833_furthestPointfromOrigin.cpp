#include<iostream>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int count = 0, curr = 0;
        for (int i = 0; i < moves.size(); i++){
            if (moves[i] == '_') count++;
            else {
                if (moves[i] == 'L') curr--;
                if (moves[i] == 'R') curr++;
            }
        }

        return max(abs(curr - count), abs(curr + count));
    }
};

int main(){
    Solution sol;
    cout << sol.furthestDistanceFromOrigin("L_RL__RL__RR") << endl;
    return 0;
}