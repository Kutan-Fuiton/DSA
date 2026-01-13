#include<iostream>
using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int x = n / 7;
        int y = n % 7;
        return (21*x + 7*((x*(x+1))/2) + y*(x+1) + ((y*(y-1))/2));
    }
};

int main(){
    Solution sol;

    cout << sol.totalMoney(69) << endl;

    return 0;
}