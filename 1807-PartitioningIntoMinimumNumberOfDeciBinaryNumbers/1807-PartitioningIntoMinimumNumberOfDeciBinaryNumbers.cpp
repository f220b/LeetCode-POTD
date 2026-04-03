// Last updated: 4/3/2026, 1:55:48 PM
class Solution {
public:
    int minPartitions(string n) {
        int maxNum = 0;
        for (char ch : n)
            maxNum = max(maxNum, ch - '0');
        return maxNum;
    }
};