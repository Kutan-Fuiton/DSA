#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0;
        int count = 0;
        int pivot;
        for (int i = 0; i < gas.size(); i++){
            count = 0;
            if (gas[i]>cost[i]){
                int j = i;
                while (tank < 0){
                    tank += gas[j] - cost[j];
                    j = (j+1)%gas.size();
                    count++;
                }
                if (tank >= 0 && count > gas.size()){return i;}
            }
        }
        if (tank < 0 && count < gas.size()+1){return -1;}
    }
};

int main(){
    Solution sol;
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    cout << sol.canCompleteCircuit(gas, cost) << endl;

    return 0;
}