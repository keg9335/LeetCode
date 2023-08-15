class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        for i in range(len(nums) + 1) :
            result.extend(list(itertools.combinations(nums, i)))
            
        return result