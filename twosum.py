class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        length = len(nums)
        for i in range(0, length):
            first = nums[i]
            for j in range(i+1, length):
                if first + nums[j] == target:
                    return [i, j]
