class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # idea: binary search (one go)
        # convert the 2d array to 1d array
        # iteratively convert to and fro from middle index of the 1D array
        # and row and col of 2d array to compare target and middle value
        # and move left and right pointer accordingly.
        ROW = len(matrix)
        COL = len(matrix[0])

        left = 0
        right = (ROW * COL) - 1  # rows * cols gives us the last index in 1d

        while left <= right:
            middle = left + (right - left) // 2
            # using this middle recalculate current value from 2d array to compare with target
            middle_row, middle_col = middle // COL, middle % COL
            # index // COL gives us which row (how many full rows can fit before current row)
            # idex % COL gives us which column of the given row
            current_val = matrix[middle_row][middle_col]
            if target < current_val:
                right = middle - 1
            elif target > current_val:
                left = middle + 1
            else:
                return True

        return False
        # time: O(log(m * n))
        # space: O(1)
