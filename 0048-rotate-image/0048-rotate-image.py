class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        temp = list(list(map(lambda x:x[j], matrix[::-1])) for j in range(len(matrix)))
        for i in range(len(matrix)):
            matrix[i] = temp[i]