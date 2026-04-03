// Last updated: 4/3/2026, 1:52:11 PM
class Solution {
public:
    int maximumConsecutive(vector<int>& arr) {
        if (arr.empty())
            return 1;

        int curr = 1, best = 1;
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1] + 1)
                curr++;
            else
                curr = 1;
            best = max(curr, best);
        }
        return best + 1;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        int side = min(maximumConsecutive(hBars), maximumConsecutive(vBars));
        return side * side;
    }
};
