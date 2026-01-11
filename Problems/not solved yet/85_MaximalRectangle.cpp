#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);
        int MAX = 0;

        for (int r = 0; r < rows; r++) {
            // histogram for rth row or current row
            for (int c = 0; c < cols; c++) {
                if (matrix[r][c] == '1')
                    heights[c]++;
                else
                    heights[c] = 0;
            }

            for (int c = 0; c < cols; c++){
                cout << heights[c] << " ";
            }
            cout << endl;

            // Largest rectangle in histogram
            stack<int> st;
            for (int i = 0; i <= cols; i++) {
                int currHeight = (i == cols) ? 0 : heights[i];

                while (!st.empty() && currHeight < heights[st.top()]) {
                    int h = heights[st.top()];
                    st.pop();
                    int w = st.empty() ? i : i - st.top() - 1;
                    MAX = max(MAX, h * w);
                }
                st.push(i);
                print(st);
                // cout << endl;
                cout << " --> " << MAX << endl;
            }
        }

        return MAX;
    }

    void print(stack<int> s) { // Pass by value (copy)
        if (s.empty()) {
            return;
        }
        
        int top = s.top();
        s.pop();
        print(s);
        cout << top << " ";
    }
};


int main(){
    Solution sol;
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    cout << sol.maximalRectangle(matrix) << endl;

    return 0;
}