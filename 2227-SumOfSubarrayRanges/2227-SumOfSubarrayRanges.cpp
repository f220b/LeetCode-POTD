// Last updated: 4/3/2026, 1:54:22 PM
class Solution {
public:
    void calculateNextGreaterAndSmaller(vector<int>& arr,
                                        vector<int>& nextGreat,
                                        vector<int>& nextSmall) {
        int n = arr.size();
        stack<int> greatStack, smallStack;

        for (int i = n - 1; i >= 0; i--) {
            // Process next greater
            while (!greatStack.empty() && arr[greatStack.top()] <= arr[i])
                greatStack.pop();
            nextGreat[i] = greatStack.empty() ? n : greatStack.top();
            greatStack.push(i);

            // Process next smaller
            while (!smallStack.empty() && arr[smallStack.top()] >= arr[i])
                smallStack.pop();
            nextSmall[i] = smallStack.empty() ? n : smallStack.top();
            smallStack.push(i);
        }
    }

    void calculatePreviousGreaterAndSmallerOrEqual(vector<int>& arr,
                                                   vector<int>& prevGreat,
                                                   vector<int>& prevSmall) {
        int n = arr.size();
        stack<int> greatStack, smallStack;

        for (int i = 0; i < n; i++) {
            // Process previous greater
            while (!greatStack.empty() && arr[greatStack.top()] < arr[i])
                greatStack.pop();
            prevGreat[i] = greatStack.empty() ? -1 : greatStack.top();
            greatStack.push(i);

            // Process previous smaller or equal
            while (!smallStack.empty() && arr[smallStack.top()] > arr[i])
                smallStack.pop();
            prevSmall[i] = smallStack.empty() ? -1 : smallStack.top();
            smallStack.push(i);
        }
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long maximumSum = 0, minimumSum = 0;

        vector<int> nextGreat(n, n), nextSmall(n, n);
        vector<int> prevGreat(n, -1), prevSmall(n, -1);

        calculateNextGreaterAndSmaller(nums, nextGreat, nextSmall);
        calculatePreviousGreaterAndSmallerOrEqual(nums, prevGreat, prevSmall);

        for (int i = 0; i < n; i++) {
            // Contribution of nums[i] as the maximum
            maximumSum +=
                (long long)(nextGreat[i] - i) * (i - prevGreat[i]) * nums[i];
            // Contribution of nums[i] as the minimum
            minimumSum +=
                (long long)(nextSmall[i] - i) * (i - prevSmall[i]) * nums[i];
        }

        return maximumSum - minimumSum;
    }
};