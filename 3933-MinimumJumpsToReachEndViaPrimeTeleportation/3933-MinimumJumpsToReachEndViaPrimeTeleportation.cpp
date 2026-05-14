// Last updated: 14/5/2026, 10:21:06 pm
class Solution {
public:
    vector<bool> isPrime;

    void buildSieve(int n) {
        isPrime.resize(n + 1, true);

        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }
    }
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mpp;
        int maxEle = INT_MIN;

        for (int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
            maxEle = max(maxEle, nums[i]);
        }

        buildSieve(maxEle);

        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        visited[0] = true;
        unordered_set<int> seenPrimes;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                int idx = q.front();
                q.pop();
                if (idx == n - 1)
                    return steps;

                if (idx - 1 >= 0 && !visited[idx - 1]) {
                    q.push(idx - 1);
                    visited[idx - 1] = true;
                }
                if (idx + 1 < n && !visited[idx + 1]) {
                    q.push(idx + 1);
                    visited[idx + 1] = true;
                }
                if (!isPrime[nums[idx]] || seenPrimes.count(nums[idx]))
                    continue;

                for (int i = nums[idx]; i <= maxEle; i += nums[idx]) {
                    if (mpp.find(i) == mpp.end())
                        continue;

                    for (int j : mpp[i]) {
                        if (!visited[j]) {
                            q.push(j);
                            visited[j] = true;
                        }
                    }
                }
                seenPrimes.insert(nums[idx]);
            }
            steps++;
        }
        return steps;
    }
};