#include <iostream>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = sum(slow);         
            fast = sum(sum(fast));    
        } while (slow != fast);

        return slow == 1;
    }

private:
    int sum(int n) {
        int s = 0;
        while (n != 0) {
            int d = n % 10;
            s += d * d;
            n /= 10;
        }
        return s;
    }
};

int main(){
    Solution sol;

    cout << sol.isHappy(86) << endl;

    return 0;
}