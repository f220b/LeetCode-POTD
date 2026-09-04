// Last updated: 9/5/2026, 12:03:05 AM
class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int idx = -1;
        for (int i = 0; i < capacity.size(); i++) {
            if (capacity[i] >= itemSize &&
                (idx == -1 || capacity[idx] > capacity[i]))
                idx = i;
        }
        return idx;
    }
};