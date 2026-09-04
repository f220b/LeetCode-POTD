// Last updated: 9/5/2026, 12:18:22 AM
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int curr = 0;
        for (int i = 0; i < n - 1; i++) {
            curr ^= derived[i];
        }
        if (curr ^ derived[n - 1] == 0)
            return true;

        curr = 1;
        for (int i = 0; i < n - 1; i++) {
            curr ^= derived[i];
        }
        if (curr ^ derived[n - 1] == 1)
            return true;

        return false;
    }
};