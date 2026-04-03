// Last updated: 4/3/2026, 1:54:09 PM
class Solution {
public:
    typedef long long ll;
    bool possible(ll minutes, int n, vector<int>& batteries) {
        ll target = minutes * n;
        for (int mins : batteries) {
            target -= min(ll(mins), minutes);
            if (target <= 0)
                return true;
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        ll low = *min_element(begin(batteries), end(batteries));
        ll sum = 0;
        for (int min : batteries)
            sum += min;
        ll high = sum / n;
        ll result = 0;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (possible(mid, n, batteries)) {
                result = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return result;
    }
};