// Last updated: 4/3/2026, 1:57:26 PM
class Solution {
public:
    int nC2(int num) { return num * (num - 1) / 2; }
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                freq[nums[i] * nums[j]]++;
            }
        }
        int count = 0;
        for (pair<int, int> i : freq) {
            count += 8 * nC2(i.second);
        }
        return count;
    }
};