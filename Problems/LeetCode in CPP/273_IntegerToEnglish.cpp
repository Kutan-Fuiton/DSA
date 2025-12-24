#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        vector<string> big = {"", " Thousand", " Million", " Billion"};

        int p = num;
        int count = 0;
        string res = "";

        while (p!=0){
            if (p%1000 != 0){
                res = threedigit(p%1000) + big[count] + (res.empty() ? "" : " " + res);
            }
            p /= 1000;
            if (p != 0) count++; 
        }

        return res;
    }
private:
    string threedigit(int n) {
        vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", 
                              "Six", "Seven", "Eight", "Nine"};
        vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                               "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", 
                              "Sixty", "Seventy", "Eighty", "Ninety"};
        string res = "";

        if (n >= 100) res = ones[n/100] + " Hundred";
        
        n %= 100;
        if (n >= 10 && n <= 19) {
            if (!res.empty()) res += " ";
            return res + teens[n-10];
        }
        
        if (n >= 20) {
            if (!res.empty()) res += " ";
            res += tens[n/10];
            n %= 10;
        }
        
        if (n > 0) {
            if (!res.empty()) res += " ";
            res += ones[n];
        }
        
        return res;
    }
};

int main(){
    Solution sol;
    int num = 1000;

    cout << sol.numberToWords(num)<<endl;
    cout << sol.numberToWords(num).size();

    return 0;
}