// Last updated: 4/3/2026, 1:54:07 PM
class Solution {
    #define ll long long
public:
    long long minimumDifference(vector<int>& nums) {
        ll n = nums.size();

        priority_queue<ll, vector<ll>, greater<ll>>minHeap;
        vector<ll> rightMaxSum(n, 0);
        ll rightSum = 0;
        for(ll i = n - 1; i >= n / 3; i--) {
            minHeap.push(nums[i]);
            rightSum += nums[i];

            if(minHeap.size() > (n / 3)) {
                rightSum -= minHeap.top();
                minHeap.pop();
            }
            if(minHeap.size() == (n / 3)) {
                rightMaxSum[i] = rightSum;
            }
        }

        priority_queue<ll, vector<ll>> maxHeap;
        ll leftSum = 0;
        ll minDiff = LLONG_MAX;

        for(ll i = 0; i < (2 * n) / 3; i++) {
            maxHeap.push(nums[i]);
            leftSum += nums[i];

            if(maxHeap.size() > (n / 3)) {
                leftSum -= maxHeap.top();
                maxHeap.pop();
            }
            if(maxHeap.size() == (n / 3)) {
                minDiff = min<ll>(minDiff, leftSum - rightMaxSum[i + 1]);
            }
        }
        return minDiff;
    }
};