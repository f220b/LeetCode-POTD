// Last updated: 4/3/2026, 1:54:02 PM
class FenwickTree {
private:
    vector<int> tree;
    int size;

public:
    FenwickTree(int n) : size(n + 1), tree(n + 2, 0) {}

    void update(int index, int delta) {
        while (index <= size) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    int query(int index) {
        int res = 0;
        while (index > 0) {
            res += tree[index];
            index -= index & -index;
        }
        return res;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> posInNums2;
        for (int i = 0; i < n; ++i) {
            posInNums2[nums2[i]] = i + 1; // Using 1-based indexing
        }

        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[i] = posInNums2[nums1[i]];
        }

        FenwickTree leftTree(n), rightTree(n);
        vector<int> leftCount(n), rightCount(n);

        for (int i = 0; i < n; ++i) {
            leftCount[i] = leftTree.query(pos[i] - 1);
            leftTree.update(pos[i], 1);
        }

        for (int i = n - 1; i >= 0; --i) {
            rightCount[i] = rightTree.query(n) - rightTree.query(pos[i]);
            rightTree.update(pos[i], 1);
        }

        long long res = 0;
        for (int i = 0; i < n; ++i) {
            res += (long long)leftCount[i] * rightCount[i];
        }

        return res;
    }
};