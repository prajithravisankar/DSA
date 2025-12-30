class Solution {
public:
    int search(vector<int>& nums, int target) {
        // idea: binary search using iteration
        // use while loop and left and right pointers to do binary search
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] < target) {
                left = middle + 1;
            } else if (nums[middle] > target) {
                right = middle - 1;
            } else {
                return middle;
            }
        }

        return -1;
    }
    // time: O(logn)
    // space: O(1)
};
