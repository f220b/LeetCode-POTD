// Last updated: 22/6/2026, 7:41:20 pm
class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (lights[i] > 0) {
                int v = lights[i];
                int left = max(0, i - v);
                int right = min(n - 1, i + v);
                diff[left]++;
                diff[right + 1]--;
            }
        }
        vector<bool> lit(n, false);
        int currLit = 0;
        for (int i = 0; i < n; i++) {
            currLit += diff[i];
            if (currLit > 0)
                lit[i] = true;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!lit[i]) {
                cnt++;
                i += 2;
            }
        }
        return cnt;
    }
};