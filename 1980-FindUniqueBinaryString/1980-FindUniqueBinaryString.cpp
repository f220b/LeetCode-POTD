// Last updated: 9/5/2026, 12:25:15 AM
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string str = "";

        for(int i = 0; i < n; i++) {
            str += ((nums[i][i] == '1') ? '0' : '1');
        }
        return str;
    }
};