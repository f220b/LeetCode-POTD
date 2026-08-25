# Last updated: 8/25/2026, 10:45:08 PM
class Solution:
    def sumGame(self, num: str) -> bool:
        leftSum, leftCnt, rightSum, rightCnt = 0, 0, 0, 0
        mid = len(num) // 2
        for i, x  in enumerate(num):
            if i < mid:
                if x == "?":
                    leftCnt += 1
                else:
                    leftSum += int(x)
            else:
                if x == "?":
                    rightCnt += 1
                else:
                    rightSum += int(x)

        if (leftCnt + rightCnt) & 1:
            return True
        return (2 * leftSum) + (9 * leftCnt) != (2 * rightSum) + (9 * rightCnt)
