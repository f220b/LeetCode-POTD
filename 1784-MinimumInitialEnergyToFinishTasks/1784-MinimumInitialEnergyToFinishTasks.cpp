// Last updated: 30/5/2026, 10:22:11 pm
class Solution {
public:
    bool static compare(const vector<int>& a, const vector<int>& b) {
        return (a[1] - a[0]) > (b[1] - b[0]);
    }
    bool isValid(int nrg, vector<vector<int>>& tasks) {
        for (auto task : tasks) {
            if (task[1] > nrg)
                return false;
            nrg -= task[0];
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), compare);
        int low = 0, high = 0;
        for (auto itr : tasks) {
            low = max(low, itr[1]);
            high += itr[1];
        }
        int ans = high;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (isValid(mid, tasks)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};