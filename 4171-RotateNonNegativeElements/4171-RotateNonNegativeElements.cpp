// Last updated: 4/3/2026, 1:48:54 PM
class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> nonNeg;
        for(int num : nums) {
            if(num >= 0)
                nonNeg.push_back(num);
        }
        int n = nonNeg.size();
        if(n == 0)
            return nums;
        k = k % n;
        if(k == 0)
            return nums;
        
        reverse(nonNeg.begin(), nonNeg.begin()+k);
        reverse(nonNeg.begin()+k, nonNeg.end());
        reverse(nonNeg.begin(), nonNeg.end());

        int i = 0, j = 0;
        while(i < nums.size() && j < n) {
            if(nums[i] >= 0) {
                nums[i] = nonNeg[j];
                j++;
            }
            i++;
        }
        return nums;
    }
};