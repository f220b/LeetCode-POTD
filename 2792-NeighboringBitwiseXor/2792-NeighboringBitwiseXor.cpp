// Last updated: 4/3/2026, 1:52:41 PM
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