# Last updated: 4/3/2026, 1:55:20 PM
class Solution(object):
    def sortSentence(self, s):
        """
        :type s: str
        :rtype: str
        """
        s1 = {}
        str = s.split()
        for i in str:
            ch = int(i[-1])
            s1[ch] = i[:-1]
        s2 = ""
        print(s1)
        for i in range(1, len(s1)+1):
            s2 = s2+" "+s1[i]
        return s2.strip()