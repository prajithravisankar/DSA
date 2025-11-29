class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // idea: binary search
        // first while loop to find the correct row (binary search the correct row)
        // second while loop to find the correct column (binary search the correct column)
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        int br = 0; // bottom row means 0th row
        int tr = ROWS - 1; // top row means from the last row and below

        while (br <= tr) {
            // this is the loop where we find the row which could potentially have our target
            int mr = br + (tr - br) / 2; 
            // middle row is used for our binary search to adjust
            // values of br, and tr.
            int firstElementOfMr = matrix[mr][0]; // first element of middle row
            int lastElementOfMr = matrix[mr][COLS - 1]; // last element of middle row

            if (target < firstElementOfMr) { // if the target is less than first element of mr
                tr--;
            } else if (target > lastElementOfMr) { // if target > last element of middle row
                br++;
            } else {
                break; // because we found potential row where our value could exist
                // because the target is not less than the first elem of middle row nor
                // greater than the last elem of middle row
            }
        }

        if (!(br <= tr)) {
            return false;
        }


        int mr = br + (tr - br) / 2;  // we declare again because the previous declaration
        // is inside the while loop and it is not available in the global scope. 

        int lc = 0;
        int rc = COLS - 1;

        while (lc <= rc) {
            // second while loop to find out if the target is present in our middle row
            // and which column
            int mc = lc + (rc - lc) / 2;
            int currentVal = matrix[mr][mc];
            if (target < currentVal) {
                rc = mc - 1;
            } else if (target > currentVal) {
                lc = mc + 1;
            } else {
                return true;
            }
        }

        return false;
    }
    // time: O(log(m) + log(n)) => O(log(m * n))
    // space: O(1)
};
