#include<iostream>
using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        while (num != 0){
            if (num%2 == 0) num/=2;
            else num--;

            count++;
        }
        return count;
    }
};

int main(){
    Solution sol;
    cout << sol.numberOfSteps(14) << endl;
    return 0;
}