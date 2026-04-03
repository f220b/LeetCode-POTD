// Last updated: 4/3/2026, 1:57:36 PM
class Solution {
public:
    bool isOdd(int num) { return num % 2 != 0; }
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (int i = 2; i < arr.size(); i++) {
            if (isOdd(arr[i - 2]) && isOdd(arr[i - 1]) && isOdd(arr[i])) {
                return true;
            }
        }
        return false;
    }
};