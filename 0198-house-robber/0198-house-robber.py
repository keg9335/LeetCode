class Solution:
    def rob(self, nums: List[int]) -> int:
        house = DefaultDict(int)
        for i in range(len(nums)):
            house[i] = max(house[i-1], house[i-2] + nums[i])
        return house[len(nums)-1]