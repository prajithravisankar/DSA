class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // idea: binary search (one pass)
        // flatten the 2d array into 1d array (treat the 2d as 1d by manipulating indices)
        // convert to and fro indices, finding middle element of 1d array, and converting that
        // middle index to the appropriate index of the 2d array and find the value of that index
        // and using that to compare that to the target
        // do this iteratively until we find the answer or not. 
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        int left = 0;
        int right = (ROWS * COLS) - 1;

        while (left <= right) {
            int middle = left + (right - left) / 2; 
            int middle_row = middle / COLS;
            int middle_col = middle % COLS;
            int current_val = matrix[middle_row][middle_col];
            if (target > current_val) {
                left = middle + 1;
            } else if (target < current_val) {
                right = middle - 1;
            } else {
                return true;
            }
        }

        return false;
    }
    // time: O(log(m * n))
    // space: O(1)
};
