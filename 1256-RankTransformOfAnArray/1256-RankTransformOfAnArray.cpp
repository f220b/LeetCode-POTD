// Last updated: 8/6/2026, 1:18:03 PM
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