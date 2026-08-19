class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> mp;
        for (const auto& seat : reservedSeats) {
            mp[seat[0]].push_back(seat[1]);
        }
        
        int save = 0;
        
        for (const auto& elem : mp) {
            const vector<int>& seats = elem.second;
            
            bool leftBlocked = false;
            bool middleBlocked = false;
            bool rightBlocked = false;
            
            for (int seat : seats) {
                if (seat >= 2 && seat <= 5) leftBlocked = true;
                if (seat >= 4 && seat <= 7) middleBlocked = true;
                if (seat >= 6 && seat <= 9) rightBlocked = true;
            }
            if (!leftBlocked && !rightBlocked) {
                save += 2; 
            } else if (!leftBlocked || !middleBlocked || !rightBlocked) {
                save += 1; 
            }
        }
        int emptyRows = n - mp.size();
        save += emptyRows * 2;
        
        return save;
    }
};