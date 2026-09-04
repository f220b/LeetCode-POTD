// Last updated: 9/5/2026, 12:29:56 AM
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int ops = target[0];
        for (int i = 1; i < n; i++) {
            if (target[i] > target[i - 1])
                ops += target[i] - target[i - 1];
        }
        return ops;
    }
};
