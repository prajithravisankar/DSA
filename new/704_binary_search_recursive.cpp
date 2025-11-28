class Solution {
public:
    int binary_search_recursive(int left, int right, vector<int>& nums, int target) {
        if (left > right) {
            return -1;
        }

        int middle = left + (right - left) / 2;

        if (nums[middle] == target) {
            return middle;
        } else {
            return (
                (nums[middle] < target) ? 
                binary_search_recursive(middle + 1, right, nums, target) : 
                binary_search_recursive(left, middle - 1, nums, target)
            );
        }
    }

    int search(vector<int>& nums, int target) {
        // idea: binary search using recursion
        // create helper function that does recursive binary search
        // the helper function should track left, right, original array, and result
        // we return the index of the result throught that helper array
        // [0, 1, 3, 4, 7, 9], and 4 -> 3
        // [0, 1, 3, 4, 7, 9], and 5 -> -1
        // [], and 10 -> -1
        // [5] and 10 -> -1
        if (nums.empty()) {
            return -1;
        } else if (nums.size() == 1 && nums[0] != target) {
            return -1;
        } else {
            return binary_search_recursive(0, nums.size() - 1, nums, target);
        }
    }
};
// time: O(logn)
// space: O(logn)
