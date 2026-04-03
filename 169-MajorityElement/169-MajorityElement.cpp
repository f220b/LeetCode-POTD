// Last updated: 4/3/2026, 2:01:49 PM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (freq == 0) {
                ans = nums[i];
            }
            if (ans == nums[i]) {
                freq++;
            } else {
                freq--;
            }
        }
        // If the majority element is not always present
        // Check the freq of ans in another loop
        // if(freq > (n/2)) YES else NO
        return ans;
    }
};