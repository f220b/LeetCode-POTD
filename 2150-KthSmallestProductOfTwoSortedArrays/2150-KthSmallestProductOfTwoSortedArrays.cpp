// Last updated: 4/3/2026, 1:54:40 PM
class Solution {
public:
    long long countLessEqual(vector<int>& A, vector<int>& B, long long x) {
        long long count = 0;
        int m = A.size(), n = B.size();

        for (int i = 0; i < m; i++) {
            long long a = A[i];
            if (a > 0) {
                int low = 0, high = n - 1, pos = -1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (a * 1LL * B[mid] <= x) {
                        pos = mid;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                if (pos != -1)
                    count += (pos + 1);
            } else if (a < 0) {
                int low = 0, high = n - 1, pos = n;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (a * 1LL * B[mid] <= x) {
                        pos = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                if (pos != n)
                    count += (n - pos);
            } else {
                if (x >= 0)
                    count += n;
            }
        }
        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
        long long low = -1e10, high = 1e10, ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;
            if (countLessEqual(nums1, nums2, mid) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
