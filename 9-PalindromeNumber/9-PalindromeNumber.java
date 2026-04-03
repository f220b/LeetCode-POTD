// Last updated: 4/3/2026, 2:04:41 PM
class Solution {
    public boolean isPalindrome(int x) {
        int rev=0,n1=x;
        while(x>0){
            int d=x%10;
            rev=(rev*10)+d;
            x/=10;
        }
        if(n1==rev)
            return true;
        else
            return false;
    }
}