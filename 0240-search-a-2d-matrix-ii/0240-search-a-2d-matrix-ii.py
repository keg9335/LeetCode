class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for row in matrix:
            if row[0] > target:
                return False
            left, right = 0, len(row)
            while left < right:
                pointer = (left + right) // 2
                if row[pointer] < target:
                    left = pointer + 1
                elif row[pointer] > target:
                    right = pointer
                else: return True
        return False

                    
            
        