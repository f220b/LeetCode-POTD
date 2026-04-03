// Last updated: 4/3/2026, 1:48:25 PM
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