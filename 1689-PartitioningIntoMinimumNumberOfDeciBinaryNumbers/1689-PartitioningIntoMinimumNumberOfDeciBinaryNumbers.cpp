// Last updated: 9/5/2026, 12:28:31 AM
class Solution {
public:
    int minPartitions(string n) {
        int maxNum = 0;
        for (char ch : n)
            maxNum = max(maxNum, ch - '0');
        return maxNum;
    }
};