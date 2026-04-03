// Last updated: 4/3/2026, 2:00:14 PM
class Solution {
    public int characterReplacement(String s, int k) {
        int[] charCount = new int[26];
        int maxCount = 0, maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            charCount[s.charAt(right) - 'A']++;
            maxCount = Math.max(maxCount, charCount[s.charAt(right) - 'A']);

            while ((right - left + 1) - maxCount > k) {
                charCount[s.charAt(left) - 'A']--;
                left++;
            }

            maxLength = Math.max(maxLength, right - left + 1);
        }

        return maxLength;
    }
}
