# Last updated: 4/3/2026, 1:55:11 PM
class Solution(object):
    def isSumEqual(self, firstWord, secondWord, targetWord):
        """
        :type firstWord: str
        :type secondWord: str
        :type targetWord: str
        :rtype: bool
        """
        s1, s2, s3 = 0, 0, 0

        for ch in firstWord:
            s1 = s1 * 10 + (ord(ch)-97)
        print(s1)

        for ch in secondWord:
            s2 = s2 * 10 + (ord(ch)-97)
        print(s2)

        for ch in targetWord:
            s3 = s3 * 10 + (ord(ch)-97)
        print(s3)

        if s1+s2 == s3:
            return True
        return False