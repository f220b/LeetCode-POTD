# Last updated: 4/3/2026, 2:00:52 PM
class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        if num==0:
            return 0
        elif num%9==0:
            return 9
        else:
            return num%9