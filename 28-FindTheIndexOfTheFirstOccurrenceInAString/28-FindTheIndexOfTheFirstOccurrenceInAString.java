// Last updated: 4/3/2026, 2:04:13 PM
class Solution {
    public int strStr(String haystack, String needle) {
        int len1=haystack.length();
        int len2=needle.length();
        int index=0;
        for(int i=0;i<len1;i++) {
            if(haystack.charAt(i)==needle.charAt(index))
                index++;
            else {
                i-=index;
                index=0;
            }
            if(index==len2)
                return i-len2+1;
        }
        return -1;   
    }
}