class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        result = []
        rows, cols = len(matrix), len(matrix[0])
        down, up = -1, rows
        left, right = -1, cols
        idx = 0

        while down < up-1 and left < right-1:
            if idx % 4 == 0:
                result.extend(matrix[down+1][left+1:right])
                down += 1
            elif idx % 4 == 1:
                result.extend(map(lambda x:x[right-1], matrix[down+1:up]))
                right -= 1
            elif idx % 4 == 2:
                result.extend(matrix[up-1][idx] for idx in range(right-1,left,-1))
                up -= 1
            else: 
                result.extend(map(lambda x: x[left+1], matrix[up-1:down:-1]))
                left +=1
            idx += 1

        return result
        