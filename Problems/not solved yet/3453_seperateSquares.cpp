#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        int min_y = INT32_MAX;
        int max_y = 0;
        for (int i = 0; i < squares.size(); i++){
            min_y = min(min_y, squares[i][1]);
            max_y = max(max_y, (squares[i][1]+squares[i][2]));
        }
        cout << "min height: " << min_y << "; max height: " << max_y << endl;
    }

    double areabelowline(vector<vector<int>>& squares, double y){
        double area = 0;
        for (int i = 0; i < squares.size(); i++){
            int h = squares[i][0];
            int k = squares[i][1];
            int side = squares[i][2];
            if (y < k + side && y > k){
                area += side*(y-k);
            } else if (y >= k + side){
                area += side * side;
            } else {
                continue;
            }
        }
        return area;
    }

    double areaAboveline(vector<vector<int>>& squares, double y){
        double area = 0;
        for (int i = 0; i < squares.size(); i++){
            int h = squares[i][0];
            int k = squares[i][1];
            int side = squares[i][2];
            if (y < k + side && y > k){
                area += side*((k+side)-y);
            } else if (y <= k) {
                area += side * side;
            } else {
                continue;
            }
        }
        return area;
    }

    double findy(vector<vector<int>>& squares, int MIN, int MAX){
        double mid = (double)MIN+((MAX-MIN)/2);
        if (areabelowline(squares, mid) == areaAboveline(squares, mid)){
            return mid;
        }
        if (MIN < MAX){
            if (areabelowline(squares, mid) < areaAboveline(squares, mid)){
                MIN = mid;
                findy(squares, MIN, MAX);
            } else {
                MAX = mid;
                findy(squares, MIN, MAX);
            }
        } 
        return -1;
    }

};

int main(){
    Solution sol;
    vector<vector<int>> squares ={
        {0,0,4},
        {1,2,2},
        {0,4,4}
    };

    cout << sol.separateSquares(squares) << endl;
    // for (int i = 1; i <= 8; i++){
    //     cout << i << ": " <<sol.areabelowline(squares, i) << " " << sol.areaAboveline(squares, i) << endl;
    // }

    // cout << sol.findy(squares, 0, 8) << endl;

    cout << sol.areabelowline(squares, 3.5) << " " << sol.areaAboveline(squares, 3.5) << endl;
    cout << sol.areabelowline(squares, 3.66667) << " " << sol.areaAboveline(squares, 3.66667) << endl;

    // cout << sol.areabelowline(squares, 1) << " " << sol.areaAboveline(squares, 1) << endl;
    // cout << sol.areabelowline(squares, 2) << " " << sol.areaAboveline(squares, 2) << endl;
    // cout << sol.areabelowline(squares, 3) << " " << sol.areaAboveline(squares, 3) << endl;
    // cout << sol.areabelowline(squares, 4) << " " << sol.areaAboveline(squares, 4) << endl;
    // cout << sol.areabelowline(squares, 5) << " " << sol.areaAboveline(squares, 5) << endl;
    // cout << sol.areabelowline(squares, 6) << " " << sol.areaAboveline(squares, 6) << endl;
    // cout << sol.areabelowline(squares, 7) << " " << sol.areaAboveline(squares, 7) << endl;
    // cout << sol.areabelowline(squares, 8) << " " << sol.areaAboveline(squares, 8) << endl;

    return 0;
}