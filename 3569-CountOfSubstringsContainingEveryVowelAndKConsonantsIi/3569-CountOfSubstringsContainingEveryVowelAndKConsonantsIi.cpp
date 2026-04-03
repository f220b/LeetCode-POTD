// Last updated: 4/3/2026, 1:51:05 PM
class Solution {
public:
    bool isVowel(char& ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    long long countOfSubstrings(string word, int k) {
        int n = word.length();
        unordered_map<char, int> mpp;
        vector<int> nextConsonant(n);
        int nxtLastConsonant = n;
        for (int i = n - 1; i >= 0; i--) {
            nextConsonant[i] = nxtLastConsonant;
            if (!isVowel(word[i])) {
                nxtLastConsonant = i;
            }
        }
        int left = 0, right = 0;
        long long count = 0;
        int numberOfConsonants = 0;
        while (right < n) {
            char ch = word[right];
            if (isVowel(ch)) {
                mpp[ch]++;
            } else {
                numberOfConsonants++;
            }
            while (numberOfConsonants > k) {
                char ch1 = word[left];
                if (isVowel(ch1)) {
                    mpp[ch1]--;
                    if (mpp[ch1] == 0) {
                        mpp.erase(ch1);
                    }
                } else {
                    numberOfConsonants--;
                }
                left++;
            }
            while (left < n && mpp.size() == 5 && numberOfConsonants == k) {
                int index = nextConsonant[right];
                count += index - right;
                char ch2 = word[left];
                if (isVowel(ch2)) {
                    mpp[ch2]--;
                    if (mpp[ch2] == 0) {
                        mpp.erase(ch2);
                    }
                } else {
                    numberOfConsonants--;
                }
                left++;
            }
            right++;
        }
        return count;
    }
};