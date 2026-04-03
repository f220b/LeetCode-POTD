// Last updated: 4/3/2026, 2:01:11 PM
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() == 1)
            return nums;
        int count1 = 0, count2 = 0;
        int ele1 = INT_MIN, ele2 = INT_MIN;
        // Extended Boyer Moore's Algorithm
        for (int i : nums) {
            if (count1 == 0 && ele2 != i) {
                ele1 = i;
                count1 = 1;
            } else if (count2 == 0 && ele1 != i) {
                ele2 = i;
                count2 = 1;
            } else if (ele1 == i)
                count1++;
            else if (ele2 == i)
                count2++;
            else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int i : nums) {
            if (ele1 == i)
                count1++;
            if (ele2 == i)
                count2++;
        }
        vector<int> ans;
        int min = (int)(nums.size() / 3) + 1;
        if (count1 >= min)
            ans.push_back(ele1);
        if (count2 >= min)
            ans.push_back(ele2);
        return ans;
    }
};