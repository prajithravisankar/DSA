class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # idea: staircase search
        max_rows = len(matrix) - 1
        current_row = 0
        current_column = len(matrix[current_row]) - 1

        while current_row <= max_rows and current_column >= 0:
            if matrix[current_row][current_column] < target:
                current_row += 1
            elif matrix[current_row][current_column] > target:
                current_column -= 1
            else:
                return True

        return False
        # time: O(m + n)
        # m = number of rows, n = number of columns
        # at most we move m rows down, or n rows left, and we skip either 1 row or
        # 1 column at each step, so it can't get worse than m + n
        # space: o(1)
