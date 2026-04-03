// Last updated: 4/3/2026, 1:54:32 PM
class Solution {
public:
    bool canAssign(int noOfTasks, vector<int>& tasks, vector<int>& workers,
                   int pills, int strength) {

        multiset<int> availableWorkers(workers.end() - noOfTasks, workers.end());
        int used_Pills = 0;
        for (int i = noOfTasks - 1; i >= 0; i--) {
            int k = tasks[i];

            auto it = availableWorkers.lower_bound(k);
            if (it != availableWorkers.end()) {
                availableWorkers.erase(it);
            } else {
                if (used_Pills == pills) {
                    return false;
                }
                it = availableWorkers.lower_bound(k - strength);
                if (it == availableWorkers.end()) {
                    return false;
                }
                used_Pills++;
                availableWorkers.erase(it);
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills,
                      int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int low = 0;
        int high = min(tasks.size(), workers.size());
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canAssign(mid, tasks, workers, pills, strength)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
