// Last updated: 9/5/2026, 12:34:07 AM
class Solution {
public:
    using vi = vector<int>;
    vi arrayRankTransform(vi& arr) {
        vi s = arr;
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        for (int i = 0; i < arr.size(); i++) 
            arr[i] = lower_bound(s.begin(), s.end(), arr[i]) - s.begin() + 1;
        return arr;
    }
};