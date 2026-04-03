// Last updated: 4/3/2026, 1:54:44 PM
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(string str : operations) {
            if(str == "++X" || str == "X++")
                x++;
            else
                x--;  
        }
        return x;
    }
};