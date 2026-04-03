// Last updated: 4/3/2026, 1:54:47 PM
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