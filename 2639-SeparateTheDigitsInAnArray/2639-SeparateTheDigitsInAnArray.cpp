// Last updated: 30/5/2026, 10:19:38 pm
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