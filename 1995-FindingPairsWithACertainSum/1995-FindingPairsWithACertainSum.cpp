// Last updated: 4/3/2026, 1:55:12 PM
class FindSumPairs {
    vector<int> a, b;             // store the two arrays
    unordered_map<int, int> freq; // value → occurrences in nums2

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        a = nums1;
        b = nums2;
        for (int v : b)
            freq[v]++; // build frequency table for nums2
    }

    // add val to nums2[index]
    void add(int index, int val) {
        int oldVal = b[index];
        freq[oldVal]--; // remove old value
        if (freq[oldVal] == 0)
            freq.erase(oldVal);

        b[index] = oldVal + val; // update nums2
        freq[b[index]]++;        // add new value
    }

    // count pairs with sum == tot
    int count(int tot) {
        long long pairs = 0; // use long long for safety
        for (int x : a) {
            int need = tot - x;
            if (freq.find(need) != freq.end())
                pairs += freq[need];
        }
        return (int)pairs; // fits in 32‑bit by constraints
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */