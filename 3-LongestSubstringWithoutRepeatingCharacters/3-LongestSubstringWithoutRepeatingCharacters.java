// Last updated: 4/3/2026, 2:04:47 PM
class Solution {
    public int lengthOfLongestSubstring(String s) {
        String s1="";
        int maxlen=0, pos=0;
        for(int i=0;i<s.length();i++) {
            if(s1.indexOf(s.charAt(i))==-1) {
                s1=s1+s.charAt(i);
            }
            else {
                if(s1.length()>maxlen) {
                    maxlen=s1.length();
                }
                s1=""+s.charAt(++pos);
                i=pos;
            }
        }
        if(s1.length()>maxlen)
            maxlen=s1.length();
        return maxlen;
    }
}