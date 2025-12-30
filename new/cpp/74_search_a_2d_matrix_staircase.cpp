class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // idea: staircase search
        // we start from the far end, the top right corner of the box, 
        // we move left or down depending on the condition that if our current value
        // is less than or greater than the target
        // if less than the target, we move one down, if greater than the target we 
        // move one left. This is possible due to the condition that the each row
        // in the given matrix is non decreasing, and the last element of each row
        // is less than the first element of the next row. Without these conditions it wouldn't
        // be possible to do staircase search. 
        int max_row = matrix.size() - 1;
        int current_row = 0;
        int current_column = matrix[current_row].size() - 1;

        while (current_row <= max_row && current_column >= 0) {
            if (matrix[current_row][current_column] > target) {
                current_column--;
            } else if (matrix[current_row][current_column] < target) {
                current_row++;
            } else {
                return true;
            }
        }

        return false;
    }
    // time: O(m + n)
    // space: O(1)
};
