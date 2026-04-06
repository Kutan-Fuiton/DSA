#include<iostream>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (const char s : moves){
            if (s == 'U') y++;
            else if (s == 'R') x++;
            else if (s == 'D') y--;
            else x--;
        }
        if (x == 0 && y == 0) return true;
        return false;
    }
};

// this is maping with functions
// #include<unordered_map>
// #include<functional>
// class Solution {
// public:
//     bool judgeCircle(string moves) {
//         int x = 0, y = 0;

//         unordered_map<char, function<void()>> map = {
//             {'U', [&x, &y](){y++;}},
//             {'R', [&x, &y](){x++;}},
//             {'D', [&x, &y](){y--;}},
//             {'L', [&x, &y](){x--;}},
//         };

//         for (const char ch : moves) {
//             map[ch]();
//             cout << x << " , " << y << endl;
//         }

//         if (x == 0 && y == 0) return true;
//         return false;
//     }
// };

int main(){
    Solution sol;

    // cout << sol.judgeCircle("UD") << endl;
    // cout << sol.judgeCircle("LL") << endl;
    cout << sol.judgeCircle("URULLDRD") << endl;

    return 0;
}