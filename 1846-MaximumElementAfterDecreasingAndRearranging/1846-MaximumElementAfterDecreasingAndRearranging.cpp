// Last updated: 9/5/2026, 12:27:04 AM
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int curr = 1, n = arr.size();
        arr[0] = curr;
        for (int i = 1; i < n; i++) {
            arr[i] = min(arr[i], curr + 1);
            curr = arr[i];
        }
        return arr[n - 1];
    }
};