class Solution:
    def binary_search(self, nums, target):
        left, right = 0, len(nums)

        while left < right:
            pointer = (left + right) //2
            if nums[pointer] < target:
                left = pointer + 1
            elif nums[pointer] > target:
                right = pointer
            else:
                return pointer
        return -1


    def search(self, nums: List[int], target: int) -> int:
        max_idx = nums.index(max(nums))
        left, right = self.binary_search(nums[:max_idx+1], target), self.binary_search(nums[max_idx+1:], target)
        result = left if left != -1 else right + max_idx + 1 if right != -1 else -1
        return result
        