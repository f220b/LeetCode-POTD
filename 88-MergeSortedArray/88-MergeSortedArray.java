// Last updated: 4/3/2026, 2:03:13 PM
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if(n==0){}
        else if(m==0) {
            for(int i=0;i<n;i++) {
                nums1[i]=nums2[i];
            }
        }
        else {
            int i=m-1, j=n-1, k=(m+n)-1;
            while(j>=0) {
                if(i>=0 && nums1[i]>nums2[j]) {
                    nums1[k--]=nums1[i--];
                }
                else {
                    nums1[k--]=nums2[j--];
                }
            }
        }
    }
}