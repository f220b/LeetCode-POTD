// Last updated: 4/3/2026, 2:02:23 PM
class Solution {
public:
    bool isPalindrome(string s) {
        string newString;

        // Filter out non-alphanumeric characters and convert to lowercase
        for (char c : s) {
            if (isalnum(c)) {
                newString += tolower(c);
            }
        }

        // Check if the filtered string is a palindrome
        int left = 0, right = newString.size() - 1;
        while (left < right) {
            if (newString[left] != newString[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};