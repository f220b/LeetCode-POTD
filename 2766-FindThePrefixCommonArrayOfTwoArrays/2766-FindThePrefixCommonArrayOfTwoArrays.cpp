// Last updated: 4/3/2026, 1:52:42 PM
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_set<int> seen;
        vector<int> result(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (seen.count(A[i])) {
                count++;
            } else {
                seen.insert(A[i]);
            }

            if (seen.count(B[i])) {
                count++;
            } else {
                seen.insert(B[i]);
            }
            result[i] = count;
        }
        return result;
    }
};