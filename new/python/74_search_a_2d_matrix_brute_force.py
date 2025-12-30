class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # idea: brute force
        for row in range(len(matrix)):
            for column in range(len(matrix[row])):
                if matrix[row][column] == target:
                    return True
        return False
        # time: O(m * n)
        # space: O(1)
