class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # idea: binary search
        # do a first while loop to find out what might be the correct row (doesn't guarentee that
        # we have the value in that row, atleast we eliminate other rows).
        # then do another while loop to find of the row we found out, if the value exists, which
        # column (cell) does it exist.
        ROWS = len(matrix)
        COLS = len(matrix[0])

        bottom_row = 0
        top_row = ROWS - 1

        while bottom_row <= top_row:
            candidate_row = bottom_row + (top_row - bottom_row) // 2
            first_element_of_current_row = matrix[candidate_row][0]
            last_element_of_current_row = matrix[candidate_row][COLS - 1]
            if target < first_element_of_current_row:
                top_row = candidate_row - 1
            elif target > last_element_of_current_row:
                bottom_row = candidate_row + 1
            else:
                break

        if not (bottom_row <= top_row):
            return False

        candidate_row = bottom_row + (top_row - bottom_row) // 2

        left_col = 0
        right_col = COLS - 1

        while left_col <= right_col:
            candidate_col = left_col + (right_col - left_col) // 2
            current_val = matrix[candidate_row][candidate_col]
            if current_val < target:
                left_col = candidate_col + 1
            elif current_val > target:
                right_col = candidate_col - 1
            else:
                return True

        return False
        # time: O(logm + logn) => O(log(m * n))
        # space: O(1)
