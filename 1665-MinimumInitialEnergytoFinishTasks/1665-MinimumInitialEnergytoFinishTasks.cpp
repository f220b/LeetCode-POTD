// Last updated: 5/12/2026, 2:17:54 PM
1class Solution {
2public:
3    bool static compare(const vector<int>& a, const vector<int>& b) {
4        return (a[1] - a[0]) > (b[1] - b[0]);
5    }
6    bool isValid(int nrg, vector<vector<int>>& tasks) {
7        for (auto task : tasks) {
8            if (task[1] > nrg)
9                return false;
10            nrg -= task[0];
11        }
12        return true;
13    }
14    int minimumEffort(vector<vector<int>>& tasks) {
15        sort(tasks.begin(), tasks.end(), compare);
16        int low = 0, high = 0;
17        for (auto itr : tasks) {
18            low = max(low, itr[1]);
19            high += itr[1];
20        }
21        int ans = high;
22        while (low <= high) {
23            int mid = low + ((high - low) >> 1);
24            if (isValid(mid, tasks)) {
25                ans = mid;
26                high = mid - 1;
27            } else {
28                low = mid + 1;
29            }
30        }
31        return ans;
32    }
33};