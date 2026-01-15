#include<iostream>
#include<vector>
using namespace std;

class Bank {
private:
    vector<long long> balances;

public:
    Bank(vector<long long>& balance) {
        balances = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if ((account1 > balances.size() || account1 <= 0) || (account2 > balances.size() || account2 <= 0)){
            return false;
        } else {
            if (money <= balances[account1-1]){
                balances[account1-1] -= (long long) money;
                balances[account2-1] += (long long) money;
                return true;
            } else {
                return false;
            }
        }
    }
    
    bool deposit(int account, long long money) {
        if (account > balances.size() || account <= 0){
            return false;
        } else {
            balances[account-1] += (long long) money;
            return true;
        }
    }
    
    bool withdraw(int account, long long money) {
        if (!(account > balances.size() || account <= 0) && money <= balances[account-1]){
            balances[account-1] -= (long long) money;
            return true;
        } else {
            return false;
        }
    }
};

int main(){
    vector<long long> balance = {100, 200, 300};

    Bank Bank(balance);   // initiated...

    cout << Bank.withdraw(2, 100) << endl;
    cout << Bank.deposit(2, 100) << endl;
    
    cout << Bank.transfer(1, 2, 200) << endl;

    return 0;
}