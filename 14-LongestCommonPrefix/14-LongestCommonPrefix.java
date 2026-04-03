// Last updated: 4/3/2026, 2:04:30 PM
class Solution {
    public String longestCommonPrefix(String[] strs) {
        Arrays.sort(strs);
        int i=0;
        while(i<strs[0].length() && i<strs[strs.length-1].length()) {
            if(strs[0].charAt(i)==strs[strs.length-1].charAt(i)) {
                i++;
            }
            else
                break;
        }
        return strs[0].substring(0,i);
    }
}