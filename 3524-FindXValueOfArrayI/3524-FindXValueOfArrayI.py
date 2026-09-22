# Last updated: 9/22/2026, 11:19:41 PM
class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        for i in range(n):
            nums[i] %= k

        ans = [0] * k
        curr = [0] * (k + 1)
        new = [0] * (k + 1)
        
        for req in range(k):    
            curr[:] = new[:] = [0] * (k + 1)
            for i in range(n - 1, -1, -1):
                for currPro in range(k, -1, -1):
                    take = notTake = 0
                    if currPro == 0:
                        count = 1 if nums[i] == req else 0
                        take = count + curr[nums[i] + 1]
                        notTake = curr[currPro]
                    else:
                        newPro = ((currPro - 1) * nums[i]) % k
                        count = 1 if newPro == req else 0
                        take = count + curr[newPro + 1]

                    new[currPro] = take + notTake
                curr, new = new, curr
            ans[req] = curr[0]
        return ans
