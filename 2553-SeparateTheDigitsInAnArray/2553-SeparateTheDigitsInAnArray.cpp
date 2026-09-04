// Last updated: 9/5/2026, 12:19:23 AM
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        for(int num : nums) {
            string str = to_string(num);
            for(char ch : str)
                result.push_back(ch - '0');
        }
        return result;
    }
};