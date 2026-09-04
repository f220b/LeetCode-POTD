# Last updated: 9/5/2026, 12:15:15 AM
class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        arr1, arr2 = [], []
        n = len(nums)

        for i, x in enumerate(nums):
            if i == 0:
                arr1.append(x)
            elif i == 1:
                arr2.append(x)
            elif arr1[-1] > arr2[-1]:
                arr1.append(x)
            else:
                arr2.append(x)
        
        arr1.extend(arr2)
        return arr1