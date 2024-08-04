class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        inter = set()
        i, j = 0, 0
        nums1.sort()
        nums2.sort()
        while i < len(nums1) and j < len(nums2):
            if nums1[i] < nums2[j]:
                i += 1
            elif nums1[i] > nums2[j]:
                j += 1
            else:
                inter.add(nums1[i])
                i += 1
                j += 1
        return inter
        