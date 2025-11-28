class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // idea: brute force
        for (int row = 0; row < matrix.size(); row++) {
            for (int column = 0; column < matrix[row].size(); column++) {
                if (matrix[row][column] == target) {
                    return true;
                }
            }
        }

        return false;
    }
    // time: O(n * m) - n = number of rows, m = number of columns
    // space: O(1)
};
