// Last updated: 11/4/2026, 11:25:53 pm
class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int limit = 100000 + 1000;
        vector<bool> isPrime(limit + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; (long long)i * i <= limit; i++) {
            if (isPrime[i])
                for (int j = i * i; j <= limit; j += i)
                    isPrime[j] = false;
        }

        vector<int> nextPrime(limit + 2, limit + 1);
        for (int i = limit; i >= 0; i--)
            nextPrime[i] = isPrime[i] ? i : nextPrime[i + 1];

        vector<int> nextNonPrime(limit + 2, limit + 1);
        for (int i = limit; i >= 0; i--)
            nextNonPrime[i] = !isPrime[i] ? i : nextNonPrime[i + 1];

        int n = nums.size(), ops = 0;
        for(int i = 0; i < n; i++) {
            if(i & 1) 
                ops += nextNonPrime[nums[i]] - nums[i];
            else
                ops += nextPrime[nums[i]] - nums[i];
        }
        return ops;
    }
};