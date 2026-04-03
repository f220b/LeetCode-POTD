// Last updated: 4/3/2026, 1:56:28 PM
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> prevNotTaken(n2 + 1, 0);
        vector<int> prevTaken(n2 + 1, 0);
        vector<int> currNotTaken(n2 + 1, 0);
        vector<int> currTaken(n2 + 1, 0);

        for (int j = 0; j <= n2; j++)
            prevNotTaken[j] = -1000000000;

        for (int i = n1 - 1; i >= 0; i--) {
            currNotTaken[n2] = -1000000000;
            for (int j = n2 - 1; j >= 0; j--) {
                int take = nums1[i] * nums2[j] + prevTaken[j + 1];
                int skipTaken = max(prevTaken[j], currTaken[j + 1]);
                int skipNotTaken = max(prevNotTaken[j], currNotTaken[j + 1]);

                currTaken[j] = max(take, skipTaken);
                currNotTaken[j] = max(take, skipNotTaken);
            }
            prevTaken = currTaken;
            prevNotTaken = currNotTaken;
        }
        return prevNotTaken[0];
    }
};
