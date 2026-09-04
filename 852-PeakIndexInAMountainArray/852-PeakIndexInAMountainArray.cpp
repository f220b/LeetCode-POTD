// Last updated: 9/5/2026, 12:37:17 AM
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1, end = arr.size() - 2;
        // Answer can never be first and last element
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (arr[mid] > arr[mid - 1] &&
                arr[mid] > arr[mid + 1]) { // Peak Index
                return mid;
            } else if (arr[mid - 1] < arr[mid]) { // Increasing Part
                st = mid + 1;
            } else { // Decreasing Part
                end = mid - 1;
            }
        }
        return -1;
    }
};