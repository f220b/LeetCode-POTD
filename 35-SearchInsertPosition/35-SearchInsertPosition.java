// Last updated: 4/3/2026, 2:04:09 PM
class Solution {
    public int searchInsert(int[] nums, int target) {
        int begin=0, end=nums.length-1;
        while(begin<=end) {
            int mid=(begin+end)/2;
            if(nums[mid]<target) {
                begin=mid+1;
            }
            else if(nums[mid]>target) {
                end=mid-1;
            }
            else
                return mid;
        }
        return begin;
    }
}