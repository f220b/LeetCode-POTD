// Last updated: 4/3/2026, 2:03:31 PM
class Solution {
    public int[] plusOne(int[] digits) {
        for(int i=0;i<digits.length;i++) {
            if(digits[i]!=9) {
                if(digits[digits.length-1]==9) {
                    int j=digits.length-1;
                    while(digits[j]==9) {
                        digits[j]=0;
                        j--;
                    }
                    digits[j]++;
                }
                else
                    digits[digits.length-1]++;
                return digits;
            }
        }
        int ans[]=new int[digits.length+1];
        ans[0]=1;
        return ans;
    }
}